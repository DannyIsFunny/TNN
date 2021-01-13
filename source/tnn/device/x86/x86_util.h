// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef TNN_X86_UTIL_H_
#define TNN_X86_UTIL_H_

#include <string.h>
#include <cstdlib>
#include <sys/time.h>

#include "tnn/core/blob.h"
#include "tnn/core/macro.h"

namespace TNN_NS {
#if TNN_PROFILE
struct Timer {
public:
    void Start() {
        gettimeofday(&start, NULL);
    }
    float TimeEclapsed() {
        struct timeval end;
        gettimeofday(&end, NULL);
        float delta = (end.tv_sec - start.tv_sec) * 1000.f + (end.tv_usec - start.tv_usec) / 1000.f;
        gettimeofday(&start, NULL);
        return delta;
    }
private:
    struct timeval start;
};
#endif

int PackC4(float *dst, const float *src, size_t hw, size_t channel);

int PackC8(float *dst, const float *src, size_t hw, size_t src_hw_stride, size_t dst_hw_stride, size_t channel);

int UnpackC4(float *dst, const float *src, size_t hw, size_t channel);

int UnpackC8(float *dst, const float *src, size_t hw, size_t src_hw_stride, size_t dst_hw_stride, size_t channel);

}  // namespace TNN_NS

#endif