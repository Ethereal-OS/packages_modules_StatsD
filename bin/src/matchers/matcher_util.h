/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MATCHER_UTIL_H
#define MATCHER_UTIL_H

#include "logd/LogEvent.h"

#include <log/log_read.h>
#include <log/logprint.h>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include "frameworks/base/cmds/statsd/src/stats_log.pb.h"
#include "frameworks/base/cmds/statsd/src/statsd_config.pb.h"
#include "stats_util.h"

namespace android {
namespace os {
namespace statsd {

enum MatchingState {
    kNotComputed = -1,
    kNotMatched = 0,
    kMatched = 1,
};

bool combinationMatch(const std::vector<int>& children, const LogicalOperation& operation,
                      const std::vector<MatchingState>& matcherResults);

bool matchesSimple(const SimpleLogEntryMatcher& simpleMatcher, const LogEvent& wrapper);

std::vector<KeyValuePair> getDimensionKey(const LogEvent& event,
                                          const std::vector<KeyMatcher>& dimensions);

}  // namespace statsd
}  // namespace os
}  // namespace android
#endif  // MATCHER_UTIL_H