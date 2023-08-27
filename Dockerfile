FROM debian:bookworm
ENV TERM xterm-256color
RUN apt-get update && apt-get install -y --fix-missing build-essential gdb
WORKDIR /app