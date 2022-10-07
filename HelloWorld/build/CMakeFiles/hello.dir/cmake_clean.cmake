file(REMOVE_RECURSE
  "../bin/hello.exe"
  "../bin/hello.exe.manifest"
  "../bin/hello.pdb"
  "../bin/libhello.dll.a"
  "CMakeFiles/hello.dir/src/hello.cpp.obj"
  "CMakeFiles/hello.dir/src/hello.cpp.obj.d"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/hello.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
