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

#ifndef EVENT_PEERCONNECTIONEVENT_H_
#define EVENT_PEERCONNECTIONEVENT_H_

#include <nan.h>
#include <webrtc/api/jsep.h>
#include "event.h"
#include "eventemitter.h"

using namespace v8;

class PeerConnectionEvent : public Event {
 public:
  explicit PeerConnectionEvent( EventEmitter *eventEmitter );
  
  void Handle();
  void SetSucceeded(bool succeeded);
  void SetErrorMessage(const std::string& errorMessage);
  
 private:
  bool _succeeded;
  std::string _errorMessage;
  EventEmitter *_eventEmitter;
};

#endif  // EVENT_PEERCONNECTIONEVENT_H_
