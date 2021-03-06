/** 
 * Copyright (c) 2015 VCO Lab CSIE department of National Taiwan University All
 * rights reserved.
 * 
 * This file is part of OpenCL Binary Search Tree for HSA comparison
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

__kernel void horizontal_kernel(__global int* a_list, int shift, int element_count) {

    /* work group size = 64, work group count = n */
    
    int gid = get_global_id(0);
    int off = gid / 64;
    
    __local int s[1024 * 4];
    
    if (a_list[off * shift] < 0) {
        a_list[off * shift] = -1;
    }
}

__kernel void vertical_kernel(__global int* a_list, int element_count) {

    /* work group size = 1, work group count = 1 */
    
    for (int i = 0; i < element_count; i++) {
        if (a_list[i] < 0) {
            a_list[i] = -1;
        }
    }
}
