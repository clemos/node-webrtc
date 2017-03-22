/*
 * Copyright (c) 2017 Axel Isouard <axel@isouard.fr>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef EVENTEMITTER_H_
#define EVENTEMITTER_H_

#include <nan.h>
#include <string>

using namespace v8;

class EventEmitter : public Nan::ObjectWrap {
 public:
  explicit EventEmitter();
  Persistent<Function>* _emit = nullptr;

  void Wrap( Local<Object> obj );
  void Emit( Local<String> type );
  void EmitData( Local<String> type, Local<Value> data );

};

#endif  // EVENTEMITTER_H_