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

#include "struct.hpp"

// Runtime Variables
Object null;

Dpp_Object *Dpp_Object::operator +(Dpp_Object *obj) {
	if(obj == nullptr || (this->reg->nb_add == nullptr)) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_add(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator -(Dpp_Object *obj) {
	if(obj == nullptr || (this->reg->nb_sub == nullptr)) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_sub(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator *(Dpp_Object *obj) {
	if(obj == nullptr || (this->reg->nb_mul == nullptr)) {
		return nullptr;
	}


	Dpp_Object *rtn = this->reg->nb_mul(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator /(Dpp_Object *obj) {
	if(obj == nullptr || (this->reg->nb_div == nullptr)) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_div(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator %(Dpp_Object *obj) {
	if(obj == nullptr || (this->reg->nb_mod == nullptr)) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_mod(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator >(Dpp_Object *obj) {
	if(obj == nullptr) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->bigger(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator <(Dpp_Object *obj) {
	if(obj == nullptr) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->smaller(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator ==(Dpp_Object *obj) {
	if(obj == nullptr) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->equal(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator !() {
	Dpp_Object *rtn = this->reg->notval(this);
	return rtn;
}

Dpp_Object *Dpp_Object::operator <<(Dpp_Object *obj) {
	if(obj == nullptr) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_shl(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator >>(Dpp_Object *obj) {
	if(obj == nullptr) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_shr(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator &(Dpp_Object *obj) {
	if(obj == nullptr) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_band(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator |(Dpp_Object *obj) {
	if(obj == nullptr) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_bor(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator ^(Dpp_Object *obj) {
	if(obj == nullptr) {
		return nullptr;
	}

	Dpp_Object *rtn = this->reg->nb_bxor(this, obj);
	return rtn;
}

Dpp_Object *Dpp_Object::operator ~() {
	Dpp_Object *rtn = this->reg->nb_bneg(this);
	return rtn;
}

bool Dpp_Object::print() {
	if(this->reg->print != nullptr) {
		bool state = this->reg->print(this);
		return state;
	} else {
		std::cout << this; // only output pointer
		return true; // success
	}
}

bool Dpp_Object::move(Dpp_Object *obj) {
	if(obj == nullptr) {
		return false; // object is null, we cannot know its type
	}

	if(this->reg->type != obj->reg->type) {
		return false; // cannot move data
	}

	std::memcpy(obj, this, sizeof(Dpp_Object) + obj->reg->size);

	return true;
}

bool Dpp_Object::moveref(Dpp_Object *obj) {
	if(this->reg->type != obj->reg->type) {
		return false; // cannot move ref data
	}

	if(obj == nullptr) {
		obj = (Dpp_Object *)malloc(sizeof(Dpp_Object) + obj->reg->size);
	}

	obj = this;

	return true; // success
}

DXX_API std::string to_string(Dpp_Object *obj) {
    if (obj->reg->to_string == nullptr) {
        return obj->reg->name;
    }

    return obj->reg->to_string(obj);
}