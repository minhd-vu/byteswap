FROM s390x/debian

RUN apt-get update && apt-get -y install g++ make gdb