#!/bin/sh
#
# throttled     This shell script takes care of starting and stopping
#               the throttled
#

# Source function library
. /etc/rc.d/init.d/functions


# Do preliminary checks here, if any
#### START of preliminary checks #########


##### END of preliminary checks #######


# Handle manual control parameters like start, stop, status, restart, etc.

case "$1" in
  start)
    # Start daemons.

    echo -n $"Starting throttled daemon: "
    echo
    daemon ./home/wkb0004/repos/throttled/throttled
    echo
    ;;

  stop)
    # Stop daemons.
    echo -n $"Shutting down throttled: "
    killproc ./home/wkb0004/repos/throttled/throttled
    echo

    # Do clean-up works here like removing pid files from /var/run, etc.
    ;;
  status)
    status ./home/wkb0004/repos/throttled/throttled

    ;;
  restart)
    $0 stop
    $0 start
    ;;

  *)
    echo $"Usage: $0 {start|stop|status|restart}"
    exit 1
esac

exit 0
