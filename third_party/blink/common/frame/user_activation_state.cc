// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/public/common/frame/user_activation_state.h"

namespace blink {

// This is a tentative timespan, which should be more than the current limit of
// 1 sec (in UGI) because we want a reasonable value that works even for a slow
// network.  Currently we are experimenting with a vary large value (eqvt to no
// expiry): https://crbug.com/776404.
constexpr base::TimeDelta kActivationLifespan =
    base::TimeDelta::FromSeconds(3600);

void UserActivationState::Activate() {
  has_been_active_ = true;
  is_active_ = true;
  activation_timestamp_ = base::TimeTicks::Now();
}

void UserActivationState::Clear() {
  has_been_active_ = false;
  is_active_ = false;
}

bool UserActivationState::IsActive() {
  if (is_active_ &&
      (base::TimeTicks::Now() - activation_timestamp_ > kActivationLifespan)) {
    is_active_ = false;
  }
  return is_active_;
}

bool UserActivationState::ConsumeIfActive() {
  if (!IsActive())
    return false;
  is_active_ = false;
  return true;
}

}  // namespace blink
