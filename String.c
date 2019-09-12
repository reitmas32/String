#include "String.h"

StringPtr new_String_void(){
  StringPtr _this = (StringPtr)calloc(1, sizeof(String));
  if(_this){

    //creacion del arreglo
    _this->string = (char*)calloc(1, sizeof(char));

    //Inicializacion de length
    _this->length = 0;
  }
  return _this;
}

StringPtr new_String(char* _data){
  StringPtr _this = (StringPtr)calloc(1, sizeof(String));
  if(_this){
    //creacion del arreglo
    _this->string = (char*)calloc(strlen(_data), sizeof(char));

    //Inicializacion de length
    _this->length = 0;

    //Inicializacion del arreglo
    for(size_t i = 0; i < strlen(_data); i++, ++_this->length){
      _this->string[i] = _data[i];
    }

  }
  return _this;
}

void   String_Delete(StringPtr _this){
  assert(_this);
  if(_this->string != NULL){
    free(_this->string);
  }
  free(_this);
}

char*  Str_get(StringPtr _this){
  return _this->string; 
}

void   Str_set(StringPtr _this, char* _data){
  assert(_this);
  free(_this->string);
  _this->string = (char*)calloc(strlen(_data), sizeof(char));

  _this->length = 0;

  for(size_t i = 0; i < strlen(_data); i++,++_this->length){
    _this->string[i] = _data[i];
  }
}

size_t Str_len(StringPtr _this){
  return _this->length;
}

void Str_addChar(StringPtr _this, char _char){
  assert(_this);
  _this->string[Str_len(_this)] =_char;
  ++_this->length;
}

bool   Str_isEmpty(StringPtr _this){
  return Str_len(_this) == 0;
}

char  Str_charAt(StringPtr _this, size_t _index){
  char* string = Str_get(_this);
  return string[_index];
}

int  Str_intAt(StringPtr _this, size_t _index){
  char* string = Str_get(_this);
  return (int)string[_index];
}

char  Str_charBefore(StringPtr _this, size_t _index){
  assert(_index > 0);
  char* string = Str_get(_this);
  return string[_index - 1];
}

int  Str_intBefore(StringPtr _this, size_t _index){
  assert(_index > 0);
  char* string = Str_get(_this);
  return (int)string[_index - 1];
}

char  Str_charAfter(StringPtr _this, size_t _index){
  assert((int)_index < (int)Str_len(_this) - 1);
  char* string = Str_get(_this);
  return string[_index + 1];
}

int  Str_intAfter(StringPtr _this, size_t _index){
  assert((int)_index < (int)Str_len(_this) - 1);
  char* string = Str_get(_this);
  return (int)string[_index + 1];
}

void  Str_toLower(StringPtr _this){
  assert(_this);
  if(!Str_isEmpty(_this)){
    for (size_t i = 0; Str_get(_this)[i]; i++)
    {
      if(_this->string[i] <= 90 && _this->string[i] > 64){
        _this->string[i] += 32;
      }
    }
  }
}

void  Str_toUpper(StringPtr _this){
  assert(_this);
  if(!Str_isEmpty(_this)){
    for (size_t i = 0;Str_get(_this)[i]; i++)
    {
      if(_this->string[i] >= 97 && _this->string[i] < 123){
        _this->string[i] -= 32;
      }
    }
  }
}

