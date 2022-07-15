BITS 64
section.text
  global _start
  _start:
    jmp _exit_SYS
  _exit_SYS:
    mov rax,60
    mov rdi,0
    syscall