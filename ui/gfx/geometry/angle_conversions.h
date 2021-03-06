// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_GEOMETRY_ANGLE_CONVERSIONS_H_
#define UI_GFX_GEOMETRY_ANGLE_CONVERSIONS_H_

#include "base/numerics/math_constants.h"
#include "ui/gfx/gfx_export.h"

namespace gfx {

GFX_EXPORT constexpr double DegToRad(double deg) {
  return deg * base::kPiDouble / 180.0;
}
GFX_EXPORT constexpr float DegToRad(float deg) {
  return deg * base::kPiFloat / 180.0f;
}

GFX_EXPORT constexpr double RadToDeg(double rad) {
  return rad * 180.0 / base::kPiDouble;
}
GFX_EXPORT constexpr float RadToDeg(float rad) {
  return rad * 180.0f / base::kPiFloat;
}

}  // namespace gfx

#endif  // UI_GFX_GEOMETRY_ANGLE_CONVERSIONS_H_
