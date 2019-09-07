#include "String.h"

void   String_Delete(struct String* _this);
char*  getString(struct String* _this);
void   setSting(StringPtr _this, char* _data);
size_t lengthString(StringPtr _this);
void   addChar(StringPtr _this, char _char);

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

size_t str_len(StringPtr _this){
    return _this->length;
}

void str_addChar(StringPtr _this, char _char){
    assert(_this);
    _this->string[str_len(_this)] =_char;
    ++_this->length;
}
