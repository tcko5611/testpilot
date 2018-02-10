#/usr/bin/env python
import os
import sys
import filecmp
from shutil import copyfile

for file in os.listdir("."):
  if file.endswith("." + sys.argv[1]):
    print(os.path.join(".", file))
    dst = "D:/msys64/home/DELL/ktcpilot/ground/gcs/src/plugins/uavobjectbrowser/" + file
    if filecmp.cmp(file, dst) :
      print "  same"
    else :
      print "  diff"
      copyfile(dst, file)
    # print(os.path.join(".", file))
