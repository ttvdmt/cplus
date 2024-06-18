cmake_minimum_required(VERSION 3.20)

function(print var)
  message("${var} = ${${var}}")
endfunction()

set(VAR "Cats and Dogs")
print(VAR)