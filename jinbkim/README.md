1. copy_wd_arr 함수에서 size가 -1이 들어오는 경우 -1을 AUTO_SIZE라고 디파인 해놓음
2. if (!get_next_line(0, &line) && line[0] == '\0') line[0] == '\0' 이면 애초에 gnl의 리턴값이 0이되기때문에 line[0] == '\0'를 지움
3. quote 상태를 -3~3 으로 enum을 이용해서 표현함
4. quote 도중에 ctrl d를 누르면 경고문은 뜨고 bash는 종료되면 안되는데 우리꺼는 종료됨. 해결하는법을 모르겠어서 unexpected_eof_error는 안쓸예정
5. split_cmds 에서 arg_quotes의 자료형 형태가 idx와 똑같기 때문에 둘중에 하나만 쓸꺼
6. 놈땜에 split_cmds안에 split을 한번더하는 함수를 넣음
7. replace_env 함수         if (ft_strncmp(&((*str)[1]), g_envp[i], idx) == 0 && ft_strlen(*str) - 1 == idx)
고침
8. count_arg_num 싹다 바꿈
9. arg_quotes 쓰는거 이해안되서 걍 안씀
