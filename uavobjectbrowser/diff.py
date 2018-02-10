#/usr/bin/env python
import os
import sys
import filecmp
for file in os.listdir("."):
  if file.endswith("." + sys.argv[1]):
    print(os.path.join(".", file))
    if filecmp.cmp(file, "D:/msys64/home/DELL/ktcpilot/ground/gcs/src/plugins/uavobjectbrowser/" + file) :
      print "  same"
    else :
      print "  diff"
    # print(os.path.join(".", file))
