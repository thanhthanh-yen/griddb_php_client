/*
    Copyright (c) 2017 TOSHIBA Digital Solutions Corporation.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _TIMESTAMPUTILS_H_
#define _TIMESTAMPUTILS_H_
#include <string>
#include "gridstore.h"
#include "GSException.h"

namespace griddb {

class TimestampUtils {
 public:
    TimestampUtils();
    ~TimestampUtils();
    static int64_t get_time_millis(int64_t timestamp);
};

} /* namespace griddb */

#endif /* _TIMESTAMPUTILS_H_ */
