#!/bin/bash
# This text file is used to generate a self-extracting gzipped tar file
# which extracts itself and accomplishes basic administrative tasks
# for installing CAS on a host.  The user may be prompted for a password 
# for certain tasks which require sudo permissions.
#
# This file has been adapted from a self-extracting
# tar example by Stuart Wells.  
# See "http://stuartwells.net/slides/selfextract.htm".
# 
CAS_BASEDIR="/opt/cas"
DEFAULT_VERSION="0000"

makeTmpDir()
{
    local DIRNAME=$1

    #first ensure we are starting clean
    rm -rf $DIRNAME
    mkdir $DIRNAME
}

rename()
{
    mv $1 $2
}

linkVersionDirs()
{
    local SRCDIR=$2
    local TGTDIR=$1

    ln -sf $SRCDIR/bin $TGTDIR/bin
    ln -sf $SRCDIR/lib $TGTDIR/lib
    ln -sf $SRCDIR/include $TGTDIR/include
}

getVersion()
{
    local VERSION

    if [ -e $TMPDIR/vesion.dat ]; then 
	VERSION=`cat $TMPDIR/vesion.dat`
    else
	VERSION=$DEFAULT_VERSION
    fi

    echo $VERSION
}

extractFiles()
{
    echo "Extracting files"

    #extract the tarball
    local SKIP=`awk '/^__TARFILE_FOLLOWS__/ { print NR + 1; exit 0; }' $0`

    #remember our file name
    local THIS=`pwd`/$0
    local TMPDIR=$CAS_BASEDIR/cas.tmp

    makeTmpDir $TMPDIR
 
    # take the tarfile and pipe it into tar
    tail +$SKIP $THIS | tar -xz

    local CAS_VERSIONDIR=$CAS_BASEDIR/cas.`getVersion`

    rename $TMPDIR $CAS_VERSIONDIR
    linkVersionDirs $CAS_BASEDIR $CAS_VERSIONDIR
}

createInstallPath()
{
    echo "Creating path: $CAS_BASEDIR"

    MODE=755
    mkdir -m $MODE -p $CAS_BASEDIR
    local ERR=$?

    if [ 0 != $ERR ]; then
	echo "FAILED to create path: $CAS_BASEDIR"
    fi

    return $ERR
}

verifyUser()
{
    if [ "root" != "$USER" ]; then
	echo "CAS must be install as root"
	return -1
    fi

    return 0
}

try()
{
    echo "trying: $@"

    $@
    local ERR=$?

    if [ 0 != $ERR ]; then
	echo "FAILED to install CAS"
	exit $ERR
    fi
}

main()
{
    local ERR

    echo ""
    echo "Installing CAS..."
    echo ""

    try verifyUser
    try createInstallPath
    try extractFiles
    
    echo "Finished"
    exit 0
}

main $@

# NOTE: Don't place any newline characters after the last line below.
__TARFILE_FOLLOWS__
