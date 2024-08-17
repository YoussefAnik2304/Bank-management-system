FROM gcc:4.9
COPY ./project /usr/src/BankManagementSystem
WORKDIR /usr/src/BankManagementSystem
RUN gcc -o BankManagementSystem main.c
CMD ["./myapp"]
