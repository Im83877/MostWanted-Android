#include "common/options.h"
#include "core/input.h"

namespace game {
bool AutoDriverPad(int port, input::Pad& pad) {
  if (port != 0) return false;
  if (Opt().cheat_auto_driver == false) return false;
  float steer = 0;
  float gas = 255;
  float brake = 0;
  bool nos = false;
  bool ok = AutoDriverCompute(steer, gas, brake, nos);
  if (ok == false) {
    steer = 0;
    gas = 150;
    brake = 80;
    nos = false;
  }
  if (steer > 1.5f) steer = 1.5f;
  if (steer < -1.5f) steer = -1.5f;
  int lx = int(steer * 32767.0f);
  if (lx > 32767) lx = 32767;
  if (lx < -32768) lx = -32768;
  pad.lx = int16_t(lx);
  pad.ly = 0;
  pad.rx = 0;
  pad.ry = 0;
  pad.buttons = 0;
  pad.analog[0] = nos ? 255 : 0;
  pad.analog[1] = 0;
  pad.analog[2] = 0;
  pad.analog[3] = 0;
  pad.analog[4] = 0;
  pad.analog[5] = 0;
  pad.analog[6] = uint8_t(brake);
  pad.analog[7] = uint8_t(gas);
  pad.connected = true;
  return true;
}
} // namespace game
