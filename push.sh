# @Author: vincent
# @Date:   2018-03-08T15:47:32+01:00
# @Filename: push.sh
# @Last modified by:   vincent
# @Last modified time: 2018-03-08T15:48:55+01:00

git add $1
git commit -am "Add Files"
git push -u origin master
