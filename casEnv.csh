# The "Clean And Simple" (CAS) software framework, tools, and documentation
# are distributed under the terms of the MIT license a copy of which is
# included with this package (see the file "LICENSE" in the CAS poject tree's
# root directory).  CAS may be used for any purpose, including commercial
# purposes, at absolutely no cost. No paperwork, no royalties, no GNU-like
# "copyleft" restrictions, either.  Just download it and use it.
# 
# Copyright (c) 2013-2015 Randall Lee White

#This file contains the top-level environment definintions
#for the CAS distributed application framework (for csh/tcsh).
#The user can copy this file to his/her home directory then
#edit the line below so that CAS_DIR points to his/her CAS working
#directory.  Source the modified file before doing any CAS
#development work.
#
#NOTE:  If the developer uses the default location, s/he can just
#source the file before doing any development work.  A symbolic
#link in his/her home directory would make sourcing the file
#convenient.


setenv CAS_DIR $HOME/Projects/cas
source $CAS_DIR/dev-scripts/cas_env.csh

#
#TODO:  Consider:  should this file should be installed in the developer's
#                  home directory as part of package installation?
