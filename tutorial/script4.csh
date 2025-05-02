#!/bin/tcsh -f
# Rund this script as:
# ./script4.csh Hello this is a tcsh script
#----------------------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------------------
# `command` is command substitution: it is raplaced by stdout of command
set now = `date` ; set mypc = `uname-a`
# Print information: variables are expanded within double quotes
echo "I am user $user working on the computer $HOST" #HOST is predefined
echo "Today the date is     : $now"
echo "My home directory is  : $home" #home is predefined
echo "My current directory is: $cwd" #cwd changes with cd
echo "My computer runs      : $mypc"
echo "My process id is      : $$   " #$$ is predefined
# Manipulate the command line: ($#argv is number of elemnets in array argv)
echo "The command line has $#argv arguments"
echo "The name of the command I am running is: $0"
echo "Arguments 3rd to last of the command   : $argv[3-]"
echo "The last argument is                   : $argv[$#argv]"
echo "All arguments                          : $argv"

# Ask user for input: eneter radii of circles
echo -n "Enter radii of circles: "
set Rs = (1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0 11.0)
if($#Rs < 10)then
 echo "Need more than 10 radii. Exiting ... "
 exit(1)
endif
echo "You entered $#Rs radii, the first is $Rs[1] and the last $Rs[$#Rs]"
echo "Rs = $Rs"

foreach R ($Rs)
  # - v rad= $R set the awk variable rad equal to $R . pi = atan2(0, -1) = 3.14....
  set l = `awk -v rad=$R 'BEGIN{print 2*atan2(0,-1)*rad}'`
  echo "Circle with R=$R has perimiter $l"
end
# alias defines a command to do what you want: use awk as a calculator

echo "Using acalc to compute          2+3=" `awk "BEGIN{print 2+3}"`
echo "Using acalc to compute  cos(2*pi) =" `awk "BEGIN{print  cos(2*atan2(0,-1))}"`

while($#Rs >0)
  set R = $Rs[1]
  shift Rs
  set a = `awk "BEGIN{print atan2(0,-1)*${R}*${R}}"`
  set file = area${R}.dat
  echo "Circle with R= $R has area $a" > $file
end

set files = (`ls -1 area*.dat`)
if ($#files == 0) echo "Sorry, no area files found"
echo "------------------------------------------------"
echo "files: $files"
ls -l $files
echo "------------------------------------------------"
echo "And the results for the area are: "
foreach f ($files)
   echo -n "file ${f}: "
   cat $f
end

echo "------------------------------------------------"

set f = $files[1] # test perimissions on first file
# -f, -r , -w, -x, -d test existence of file , rwxd permissions
# the ! negates the expression ( true --> false , false --> true

echo "testing permissions on files:"
if( -f $f     ) echo "$file exists"
if( -r $f     ) echo "$file is readable by me"
if( -w $f     ) echo "$file is writable by me"
if(! -w /bin/ls) echo "/bin/ls is NOT writable by me"
if(! -x $f     ) echo "$file is NOT an executable"
if( -x /bin/ls) echo "/bin/ls is executable by me"
if(! -d $f    ) echo "$file is not a directory"
if( -d /bin   ) echo "/bin is a directory"

#transform the name of a file

set f = $cwd/$f
set filename = $f:r
set extension = $f:e
set fdir = $f:h
set base = `basename $f`

echo "file is: $f"
echo "filename is $filename"
echo "extension is $extension"
echo "directory is $fdir"
echo "basename is $base"

set newfile = ${filename}.jpg
echo "jpeg name is: $newfile"
echo "jpeg base is: " `basename $newfile`

if ($newfile:e == jpg)echo `basename $newfile` " is a picture"
echo "------------------------------------------------"


cat <<AREAS >> areas.dat

`cat $files`
AREAS

if( -f areas.dat) cat areas.dat

gnuplot <<EOF
set terminal png
set output "areas.png"
plot "areas.dat" using 4:7 title "areas.dat", pi*x*x title "pi*R^2"

replot

EOF

if( -f areas.png) eog areas.png &

