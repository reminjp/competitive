#!/bin/bash

ftp -n <<END
  open 157.7.52.186
  user cpaw_user 5f4dcc3b5aa765d61d8327deb882cf99
  get .hidden_flag_file -
END
# cpaw{f4p_sh0u1d_b3_us3d_in_3ncryp4i0n}
