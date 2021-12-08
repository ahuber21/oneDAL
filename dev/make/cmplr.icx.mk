#===============================================================================
# Copyright 2012-2021 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#===============================================================================

#++
#  Intel compiler defenitions for makefile
#--

PLATs.icpx = lnx32e

CMPLRDIRSUFF.icpx = _icpx

CORE.SERV.COMPILER.icpx = generic

-Zl.icpx =
-DEBC.icpx = -g

COMPILER.lnx.icpx = icpx $(if $(IA_is_ia32),-m32,-m64) \
                     -Werror -Wreturn-type


link.dynamic.lnx.icpx = icpx $(if $(IA_is_ia32),-m32,-m64)

pedantic.opts.icpx = -pedantic \
                      -Wall \
                      -Wextra \
                      -Wno-unused-parameter

pedantic.opts.lnx.icpx = $(pedantic.opts.icpx)

p4_OPT.icpx   = $(-Q)march=nocona
mc_OPT.icpx   = $(-Q)march=core2
mc3_OPT.icpx  = $(-Q)march=nehalem
avx_OPT.icpx  = $(-Q)march=sandybridge
avx2_OPT.icpx = $(-Q)march=haswell
skx_OPT.icpx  = $(-Q)march=skx