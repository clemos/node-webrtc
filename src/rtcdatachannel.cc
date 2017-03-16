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

#include <iostream>
#include <webrtc/api/datachannelinterface.h>
#include "rtcdatachannel.h"
#include "common.h"

static const char sRTCDataChannel[] = "RTCDataChannel";

static const char kLabel[] = "label";
static const char kOrdered[] = "ordered";
static const char kReadyState[] = "readyState";

NAN_MODULE_INIT(RTCDataChannel::Init) {
  Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(New);
  ctor->SetClassName(LOCAL_STRING(sRTCDataChannel));
  ctor->InstanceTemplate()->SetInternalFieldCount(1);

  Local<ObjectTemplate> prototype = ctor->PrototypeTemplate();
  Nan::SetAccessor(prototype, LOCAL_STRING(kLabel), GetLabel);
  Nan::SetAccessor(prototype, LOCAL_STRING(kOrdered), GetOrdered);
  Nan::SetAccessor(prototype, LOCAL_STRING(kReadyState), GetReadyState);
  
  constructor().Reset(Nan::GetFunction(ctor).ToLocalChecked());

  Nan::Set(target, LOCAL_STRING(sRTCDataChannel), ctor->GetFunction());
}

RTCDataChannel::RTCDataChannel(
    const rtc::scoped_refptr<webrtc::DataChannelInterface> &datachannel)
    : _datachannel(datachannel) {
}

RTCDataChannel::~RTCDataChannel() {}

Local<Object> RTCDataChannel::Create(
  const rtc::scoped_refptr<webrtc::DataChannelInterface> &datachannel) {
  Local<Function> cons = Nan::New(RTCDataChannel::constructor());
  Local<Object> instance = Nan::NewInstance(cons, 0, NULL).ToLocalChecked();

  RTCDataChannel *_datachannel = new RTCDataChannel(datachannel);
  _datachannel->Wrap(instance);

  return instance;
}

NAN_METHOD(RTCDataChannel::New) {
}

NAN_GETTER(RTCDataChannel::GetLabel) {
  UNWRAP_OBJECT(RTCDataChannel, object);
  info.GetReturnValue().Set(LOCAL_STRING(object->_datachannel->label()));
}

NAN_GETTER(RTCDataChannel::GetOrdered) {
  UNWRAP_OBJECT(RTCDataChannel, object);
  info.GetReturnValue().Set(object->_datachannel->ordered());
}

NAN_GETTER(RTCDataChannel::GetReadyState) {
  UNWRAP_OBJECT(RTCDataChannel, object);
  const char* readyState = webrtc::DataChannelInterface::DataStateString(object->_datachannel->state());
  info.GetReturnValue().Set(LOCAL_STRING(readyState));
}
