#include "common/options.h"
#include "core/input.h"

namespace game {

bool AutoDriverPad(int port, input::Pad& pad) {
  if (port == 0) {
  } else { return false; }
  if (Opt().cheat_auto_driver == false) return false;
  pad.lx = 0;
  pad.ly = 0;
  pad.rx = 0;
  pad.ry = 0;
  pad.buttons = 0;
  pad.analog[7] = 255;
  pad.analog[6] = 0;
  pad.connected = true;
  return true;
}
} // namespace game
