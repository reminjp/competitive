#!/bin/bash

file misc100.zip
# misc100.zip: OpenDocument Drawing
file --mime-type misc100.zip
# misc100.zip: application/vnd.oasis.opendocument.graphics
cp misc100.zip misc100.odg
# open it with Microsoft Word
# cpaw{It_is_fun__isn't_it?}
