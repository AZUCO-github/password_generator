# パスワードジェネレータ
rev.2024/04/17

-コマンドラインのオプションの説明  
/u    アルファベット大文字は使用しない  
/l    アルファベット小文字は使用しない  
/n    数字は使用しない  
/s    記号は使用しない  
/d(d) パスワードの桁数を10進数で指定。デフォルトは32  
/t(d) 生成するパスワードの数を10進数で指定  

password_generator >password_list.csv  
といった感じにリダイレクトで出力する事を想定して、コンマとダブルクオートの出力をデフォルトで抑制しています。  
