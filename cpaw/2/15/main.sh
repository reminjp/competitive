#!/bin/bash

curl -sI http://q15.ctf.cpaw.site | grep -E 'cpaw{.+}'
# X-Flag: cpaw{4re_y0u_1ook1ng_http_h3ader?}
