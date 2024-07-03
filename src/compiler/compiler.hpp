/*
  MIT License

  Copyright (c) 2023 ACoderOrHacker

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 */

#ifndef _COMPILER_H

#include <string>
#include <fstream>
#include <any>
#include <cstdarg>

#include "DXXLexer.h"
#include "DXXParserBaseVisitor.h"
#include "vm.hpp"

bool compile(std::string code);
bool compile(std::ifstream file);


void underlineError(antlr4::Recognizer *recognizer,
	                antlr4::Token *offendingSymbol,
	                size_t line,
	                size_t charPositionInLine);
/*
class ErrorListener : public antlr4::BaseErrorListener {
public:
	ErrorListener(){}
	~ErrorListener(){}

	void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
		size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
		std::cerr << "Syntax error at line " << line << ", column " << charPositionInLine << ": " << msg << std::endl;
		//underlineError(recognizer, offendingSymbol, line, charPositionInLine);
	}

	void reportAmbiguity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact,
		const antlrcpp::BitSet &ambigAlts, antlr4::atn::ATNConfigSet *configs){}

	void reportAttemptingFullContext(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		const antlrcpp::BitSet &conflictingAlts, antlr4::atn::ATNConfigSet *configs){}

	void reportContextSensitivity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		size_t prediction, antlr4::atn::ATNConfigSet *configs){}
};
*/

typedef struct _Dpp_CObject {
	Object object;
    std::wstring id;
    uint32_t infos;
    Array<_Dpp_CObject *> subs;
	void *metadata[8];
} Dpp_CObject;

class Namespace {
public:
    Array<Dpp_CObject *> objects;
	Array<Namespace *> namespaces;
};

void writeInfos(Dpp_Object *o, std::vector<DXXParser::InfoContext *> *infos) {

}

void writeType(FObject *fObj, Dpp_Object *o, Object type) {
	if (type.isInGlobal && type.id < TYPE_END) {
		// the type is registered type
		o->reg = fObj->obj_map.get(type)->reg;
		return;
	}

	o->reg = nullptr; // the object type is unknown or the object is a class
}

Object newObject(FObject *fObj,
	Object type,
	Object val = Dpp_Null) {

}

DXX_API OpCode MakeOpCode(rt_opcode op,
    char flags = NO_FLAG,
    int count = 0,
    ...) {
    OpCode _op;
    _op.opcode = op;
    _op.flag = flags;
    va_list l;
    va_start(l, count);
    for(int i = 0; i<count; ++i) {
        _op.params.PushData(va_arg(l, Object));
    }
    va_end(l);

    return _op;
}

class DXXVisitor : public DXXParserBaseVisitor {
public:
    DXXVisitor(FObject *_fObj = nullptr) {
        _fObj == nullptr ? fObj = new FObject : fObj = _fObj;
    }

    /*
     * @return: NONE
     * Create 'import' opcodes
     */
    std::any visitImportLib(DXXParser::ImportLibContext *ctx) override {
        Dpp_CObject *library = MakeString(ctx->idEx()->toString());

        LoadOpcode(OPCODE_IMPORT, NO_FLAG, 1, library);
        return NONE;
    }

    /*
     * @return: Dpp_CObject *
     * Create a 'Compile-time Object' of function
     */
    std::any visitFunctionHead(DXXParser::FunctionHeadContext *ctx) override {
        std::vector<DXXParser::InfoContext *> &_infos = ctx->info();
        std::string &id = ctx->ID()->toString();
        DXXParser::ParamListContext *_params = ctx->paramList();
        DXXParser::TheTypeContext *retType = ctx->theType();
        DXXParser::ThrowtableContext *throwTable = ctx->throwtable();

        uint32_t infos = GetInfos(_infos);
        Heap<Dpp_Object *> *params = anycast(Heap<Dpp_Object *> *, visitParamList(_params));
        Dpp_Object *ret = anycast(Dpp_Object *, visitTheType(retType));
        Heap<Dpp_Object *> *throws = anycast(Heap<Dpp_Object *> *, visitThrowtable(throwTable));

        FunctionObject func = ;
        Dpp_CObject *co;

        o = mkFunctionConst(id);
        dbgInfos = mkFunctionDbgInfos(infos, id, throws);
        writeDbgInfos(dbgInfos);

        return std::any(o);
    }

    std::any visitFunction(DXXParser::FunctionContext *ctx) override {

    }

	std::any visitVarDefine(DXXParser::VarDefineContext *ctx) {
		DXXParser::TheTypeContext *_type = ctx->theType();
		std::vector<DXXParser::InfoContext *> infos = ctx->info();
		DXXParser::DataContext *_data = ctx->data();

		std::string id = ctx->ID()->toString();
		Object type = anycast(Object, visitTheType(_type));

		Object data = Dpp_Null;

		if (_data != nullptr) {
			data = anycast(Object, visitChildren(_data));
		}

		Object omapping = newObject(type, data);

		return std::any(omapping);
	}

	std::any visitVarSet(DXXParser::VarSetContext *ctx) override {
		Object o = anycast(Object, visitIdEx(ctx->idEx()));
		Object val = anycast(Object, visitChildren(ctx->data()));

		movVal(o, val);

		return std::any(o);
	}

	std::any visitFunction(DXXParser::FunctionContext *ctx) override {
		// 1.Create a function head (visitFunctionHead)
		// 2.Write opcodes into function (visitBlock)
		// pop the function state, make function object


        DXXParser::FunctionHeadContext *head = ctx->functionHead();
		DXXParser::BlockContext *block = ctx->block();

		struct VMState state;
		fObj->callstack.push(fObj->state);
		fObj->state = state;

		Dpp_Object *func = anycast(Dpp_Object *, visitFunctionHead(head));
		visitBlock(block);

		((FunctionObject *)func)->state = fObj->state;

		fObj->state = fObj->callstack.top();
		fObj->callstack.pop();
	}

	std::any visitFunctionDefine(DXXParser::FunctionDefineContext *ctx) override {
		return visitFunctionHead(ctx->functionHead());
	}
	/*
	std::any visitTypedef(DXXParser::TypedefContext *ctx) override {
		std::string id = ctx->ID()->toString();
		DXXParser::TheTypeContext *type = ctx->theType();

		Object type = anycast(Object, visitTheType(type));


	}*/

	std::any visitNew(DXXParser::NewContext *ctx) override {
		Object type = anycast(Object, visitTheType(ctx->theType()));

		return std::any(newType(type));
	}

	std::any visitDelete(DXXParser::DeleteContext *ctx) override {
		Object data = anycast(Object, visitChildren(ctx->data()));

		deleteData(data);
		return nullptr;
	}

	std::any visitBlock(DXXParser::BlockContext *ctx) override {
		for (auto it : ctx->expressions()) {
			visitChildren(it);
		}

		return nullptr;
	}

private:
    /*
     * @return: bool
     */
    inline bool isInGlobal() { return globalNamespace == thisNamespace; }

    /*
     * @return: Object
     * Create a Object structure from the iterator
     */
    Object allocMapping(bool isConst = false) {
        if (isConst) return {true, ++this->globalNamespace->idIt};
        else return {isInGlobal(), ++this->thisNamespace->idIt};
    }

    /*
     * @return: void
     * Create a opcode and push it to main state(fObj->state)
     */
    void LoadOpcode(rt_opcode op,
                    char flags = NO_FLAG,
                    int count = 0,
                    ...) {
        va_list l;

        va_start(l, count);
        fObj->state.vmopcodes.PushData(MakeOpCode(op, flags, count, l));
        va_end(l);
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md)
     * And Push the constant to the object pool
     */
    Dpp_CObject *MakeConst(Object o, Dpp_Object *obj) {
        Dpp_CObject *_co = new Dpp_CObject;
        _co->object = o;

        fObj->obj_map.write(o, obj);

        return _co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of StringObject
     * And Push the string constant to the object pool
     */
    Dpp_CObject *MakeString(std::string s) {
        String wstr = stringToWstring(s);
        Object o = allocMapping(true);
        Dpp_Object *obj = mkConst<StringObject, String>(wstr);

        return MakeConst(o, obj);
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of FunctionObject
     * And Push the function object to the object pool
     */
    Dpp_CObject *MakeFunction() {

        return MakeConst(o, obj);
    }

    /*
     * @return: Dpp_Object *
     * Make a function object(run-time)
     */
    Dpp_Object *MakeFunctionObject(std::string id) {
        FunctionObject *func = NewObject<FunctionObject>();
        Dpp_Object *o = cast(Dpp_Object *, func);

        o->name = id;
        o->isTypeObject = false;
        o->reg = FunctionType;
        // TODO: NOT SUCCESS
        //o->info
    }

	void writeDbgInfos(Dpp_DbgInfos *infos) {
		thisNamespace->objects.write(thisNamespace->idIt, infos);
		++this->thisNamespace;
	}

	uint32_t getInfos(std::vector<DXXParser::InfoContext *> *_infos) {
		uint32_t infos;

		for (auto it : *_infos) {
			infos &= anycast(uint32_t, visitInfo(it));
		}
	}

	Dpp_Object *mkFunctionConst(std::string id) {
		Dpp_Object *o = NewObject<FunctionObject>();
		newObject(o, id);

		return o;
	}

	Dpp_DbgInfos *mkFunctionDbgInfos(uint32_t infos,
		std::string id,
		Heap<Dpp_Object *> *throws) {
		Dpp_DbgInfos *ret = new Dpp_DbgInfos;

		ret->infos = infos;
		ret->id = id;
		ret->metadata[0] = throws; // see doc/compiler/metadata.md
	}

	void newObject(Dpp_Object *o,
		std::string id) {
		o->name = id;
	}

	Object newType(Object type) {
		Object to = allocMapping();
		OpCode op;
		Heap<Object> params;

		op = {
			OPCODE_NEW,
			NO_FLAG,
			params
		};

		op.params.PushData(type);
		op.params.PushData(to);

		fObj->state.vmopcodes.PushData(op);
	}

	void deleteData(Object data) {
		OpCode op;
		Heap<Object> params;

		op = {
			OPCODE_DELETE,
			NO_FLAG.
			params
		};

		op.params.PushData(data);

		fObj->state.vmopcodes.PushData(op);
	}

	Object newObject(Object type,
		Object val = Dpp_Null) {
		Heap<Object> params; // opcode paramters
		OpCode op;
		Object to = allocMapping();

		op = {
			OPCODE_NEW,
			NO_FLAG,
			params
		};

		op.params.PushData(type);
		op.params.PushData(to);

		fObj->state.vmopcodes.PushData(op);
		if (!(val == Dpp_Null)) {
			movVal(to, val);
		}

		return to;
	}

	void movVal(Object src,
		Object val) {
		OpCode op;
		Heap<Object> params;

		op = {
			OPCODE_MOV,
			NO_FLAG,
			params
		};

		op.params.PushData(src);
		op.params.PushData(val);

		fObj->state.vmopcodes.PushData(op);
	}
private:
	FObject *fObj;
    Namespace *globalNamespace = new Namespace;
    Namespace *thisNamespace = globalNamespace;
};

#endif // !_COMPILER_H
