#!/bin/bash - 


for i in */*/*/*.docx  ; do
	echo "$i"
	x="$( dirname "$i")"
	libreoffice --headless -convert-to pdf "$i" -outdir "$x"
	if [ -e "$i" ] ; then
		rm "$i"
	fi
	echo "$x"
done
for i in */*/*.docx  ; do
	echo "$i"
	x="$( dirname "$i")"
	libreoffice --headless -convert-to pdf "$i" -outdir "$x"
	if [ -e "$i" ] ; then
		rm "$i"
	fi
	echo "$x"
done
for i in */*.docx  ; do
	echo "$i"
	x="$( dirname "$i")"
	libreoffice --headless -convert-to pdf "$i" -outdir "$x"
	if [ -e "$i" ] ; then
		rm "$i"
	fi
	echo "$x"
done
