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

#include <iostream>
#include "struct.hpp"
#include "objects.hpp"

// Runtime Variables
Object null;

Dpp_Object *Dpp_Object::operator +(Dpp_Object *obj) {
    return add(this, obj);
}

Dpp_Object *Dpp_Object::operator -(Dpp_Object *obj) {
	return sub(this, obj);
}

Dpp_Object *Dpp_Object::operator *(Dpp_Object *obj) {
	return mul(this, obj);
}

Dpp_Object *Dpp_Object::operator /(Dpp_Object *obj) {
	return div(this, obj);
}

Dpp_Object *Dpp_Object::operator %(Dpp_Object *obj) {
	return mod(this, obj);
}

Dpp_Object *Dpp_Object::operator >(Dpp_Object *obj) {
	return bigger(this, obj);
}

Dpp_Object *Dpp_Object::operator <(Dpp_Object *obj) {
    return smaller(this, obj);
}

Dpp_Object *Dpp_Object::operator ==(Dpp_Object *obj) {
	return equal(this, obj);
}

Dpp_Object *Dpp_Object::operator !() {
	return notval(this);
}

Dpp_Object *Dpp_Object::operator <<(Dpp_Object *obj) {
	return shl(this, obj);
}

Dpp_Object *Dpp_Object::operator >>(Dpp_Object *obj) {
	return shr(this, obj);
}

Dpp_Object *Dpp_Object::operator &(Dpp_Object *obj) {
	return band(this, obj);
}

Dpp_Object *Dpp_Object::operator |(Dpp_Object *obj) {
	return bor(this, obj);
}

Dpp_Object *Dpp_Object::operator ^(Dpp_Object *obj) {
	return bxor(this, obj);
}

Dpp_Object *Dpp_Object::operator ~() {
	return bneg(this);
}

// TODO: there are 3 functions no define
Dpp_Object *Dpp_Object::move(Dpp_Object *obj) {
    if (typeid(this) != typeid(obj)) {
        return nullptr;
    }

    dpp::_delete_object(obj);
    obj = this->new_object();
    *obj = *this;

    return obj;
}

bool Dpp_Object::moveref(Dpp_Object *obj) {
    return true;
    /*
	if(this->reg->type != obj->reg->type) {
		return false; // cannot move ref data
	}

	if(obj == nullptr) {
		obj = (Dpp_Object *)malloc(sizeof(Dpp_Object) + obj->reg->size);
        if (obj == nullptr) return false;
	}

	obj = this;

	return true; // success*/
}

DXX_API std::string to_string(Dpp_Object *obj) {
    return std::string("");
    /*
    if (obj == nullptr) {
        return "unknown";
    }

    if (obj->reg == nullptr) {
        return obj->name;
    }

    if (obj->reg->to_string == nullptr) {
        return obj->reg->name;
    }

    return obj->reg->to_string(obj);*/
}