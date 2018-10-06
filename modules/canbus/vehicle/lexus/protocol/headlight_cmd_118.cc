/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/lexus/protocol/headlight_cmd_118.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace lexus {

using ::apollo::drivers::canbus::Byte;

const int32_t Headlightcmd118::ID = 0x118;

// public
Headlightcmd118::Headlightcmd118() { Reset(); }

uint32_t Headlightcmd118::GetPeriod() const {
  // TODO(QiL) modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Headlightcmd118::UpdateData(uint8_t* data) {
  set_p_ignore_overrides(data, ignore_overrides_);
  set_p_enable(data, enable_);
  set_p_clear_override(data, clear_override_);
  set_p_clear_faults(data, clear_faults_);
  set_p_headlight_cmd(data, headlight_cmd_);
}

void Headlightcmd118::Reset() {
  // TODO(QiL) you should check this manually
  ignore_overrides_ = false;
  enable_ = false;
  clear_override_ = false;
  clear_faults_ = false;
  headlight_cmd_ = Headlight_cmd_118::HEADLIGHT_CMD_HEADLIGHTS_OFF;
}

Headlightcmd118* Headlightcmd118::set_ignore_overrides(bool ignore_overrides) {
  ignore_overrides_ = ignore_overrides;
  return this;
}

// config detail: {'name': 'IGNORE_OVERRIDES', 'offset': 0.0, 'precision': 1.0,
// 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 1,
// 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
void Headlightcmd118::set_p_ignore_overrides(uint8_t* data,
                                             bool ignore_overrides) {
  int x = ignore_overrides;

  Byte to_set(data + 0);
  to_set.set_value(x, 1, 1);
}

Headlightcmd118* Headlightcmd118::set_enable(bool enable) {
  enable_ = enable;
  return this;
}

// config detail: {'name': 'ENABLE', 'offset': 0.0, 'precision': 1.0, 'len': 1,
// 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 0, 'type': 'bool',
// 'order': 'motorola', 'physical_unit': ''}
void Headlightcmd118::set_p_enable(uint8_t* data, bool enable) {
  int x = enable;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}

Headlightcmd118* Headlightcmd118::set_clear_override(bool clear_override) {
  clear_override_ = clear_override;
  return this;
}

// config detail: {'name': 'CLEAR_OVERRIDE', 'offset': 0.0, 'precision': 1.0,
// 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 2,
// 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
void Headlightcmd118::set_p_clear_override(uint8_t* data, bool clear_override) {
  int x = clear_override;

  Byte to_set(data + 0);
  to_set.set_value(x, 2, 1);
}

Headlightcmd118* Headlightcmd118::set_clear_faults(bool clear_faults) {
  clear_faults_ = clear_faults;
  return this;
}

// config detail: {'name': 'CLEAR_FAULTS', 'offset': 0.0, 'precision': 1.0,
// 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 3,
// 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
void Headlightcmd118::set_p_clear_faults(uint8_t* data, bool clear_faults) {
  int x = clear_faults;

  Byte to_set(data + 0);
  to_set.set_value(x, 3, 1);
}

Headlightcmd118* Headlightcmd118::set_headlight_cmd(
    Headlight_cmd_118::Headlight_cmdType headlight_cmd) {
  headlight_cmd_ = headlight_cmd;
  return this;
}

// config detail: {'name': 'HEADLIGHT_CMD', 'enum': {0:
// 'HEADLIGHT_CMD_HEADLIGHTS_OFF', 1: 'HEADLIGHT_CMD_LOW_BEAMS', 2:
// 'HEADLIGHT_CMD_HIGH_BEAMS'}, 'precision': 1.0, 'len': 8, 'is_signed_var':
// False, 'offset': 0.0, 'physical_range': '[0|2]', 'bit': 15, 'type': 'enum',
// 'order': 'motorola', 'physical_unit': ''}
void Headlightcmd118::set_p_headlight_cmd(
    uint8_t* data, Headlight_cmd_118::Headlight_cmdType headlight_cmd) {
  int x = headlight_cmd;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 8);
}

}  // namespace lexus
}  // namespace canbus
}  // namespace apollo
