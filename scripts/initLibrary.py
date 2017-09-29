#!/usr/bin/python

import os, sys
import shutil

PATH = '/tmp/.CTPP'

if __name__ == '__main__':

  sourceDir = sys.argv[1]

  if os.path.exists(PATH) == False:

    # Create work dir
    print("-- [initLibrary.py] Create work dir for CToPyPlot: %s" %PATH)
    os.makedirs(PATH)

    # Copy python script in work dir
    print("-- [initLibrary.py] Copy python script in work dir : %s/DrawVector.py" %PATH)
    tmpScript = sourceDir + "/DrawVector.py"
    shutil.copy(tmpScript, PATH)