dlltool -k -d libfmodex-min.def -l libfmodex.a #FMODEx mingw symbols were not available - had to create .def with minimal amount of symbols aliased to vc symbol ordinals.
dlltool -k -d libzoidcom_wm.def -l libzoidcom_vc.a #zoidcom's mingw dll was bugged - had to create .def with symbols aliased (collected from libzoidcom_wm.def) to vc symbol ordinals.