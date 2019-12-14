#!/bin/bash

cat directories/*/*/*.txt | grep -A 1 -i 'flagis' | sed -E 's/(.+->|--|\n)//g' | sed -e ':a' -e 'N' -e '$!ba' -e 's/\n//g'
# flag{Gr3p_c0mmBo7o4nd_h45_m4ny_0ptUT10n5!}
