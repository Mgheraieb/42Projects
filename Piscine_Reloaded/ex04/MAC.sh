ifconfig | grep ether | sed 's/ether//g' | tr -d "\t" |sed 's/ //g'
