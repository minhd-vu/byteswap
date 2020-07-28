FROM s390x/ubuntu

RUN apt-get -y update && apt-get -y install g++ make gdb

CMD ["--cap-add=SYS_PTRACE", "--security-opt", "seccomp=unconfined"]