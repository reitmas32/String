#ifndef STRING_H
#define STRING_H

/**!< Biblioteca estandar para printf y scanf*/
#include <stdio.h>

/**!< Para los bool*/
#include <stdbool.h>

/**!< Para funciones de memoria dinamica*/
#include <stdlib.h>


#include <string.h>

/**!< Para los assert*/
#include <assert.h>

/**
  * @brief  Estructura String
  */
typedef struct String
{
    char* string;
    size_t length;
}String;

/** Redefino String* como StringPtr*/
typedef struct String* StringPtr;

/**
  * @brief   new_String_void        Constructor vacio de un String 
  * @return  _this                  
  */
StringPtr new_String_void();

/**
  * @brief   new_String             Constructor para un String
  * @param   _data                  cadena que sera contenida en el String
  * @return  _this                  StringPtr creado
  */
StringPtr new_String(char* _data);

/**
  * @brief   new_StringCpy          Constructor por copia para un String
  * @param   _other                 String del cual sera copiado el String que se generara
  * @return  _this                  StringPtr creado
  */
StringPtr new_StringCpy(StringPtr _other);

/**
  * @brief   String_Delete          Destructor del String
  * @param   _this                  String a borrar
  */
void   String_Delete(StringPtr _this);

/**
  * @brief   Str_get                Retorna el contenido del string
  * @param   _this                  String refernciado
  * @return  _this-string           contenido del String
  */
char*  Str_get(StringPtr _this);

/**
  * @brief   Str_set                Cambia el contenido del string
  * @param   _this                  String refernciado
  */
void   Str_set(StringPtr _this, char* _data);

/**
  * @brief   Str_len                Retorna la longitud del String
  * @param   _this                  String refernciado
  * @return  _this-len              longitud del String
  */
size_t str_len(StringPtr _this);

/**
  * @brief   Str_addChar            Agrega un caracter al final de la cadena
  * @param   _this                  String refernciado
  */
void   str_addChar(StringPtr _this, char _char);


#endif
