# timestamp
一个小轮子，实现将`A`的文件属性时间戳，赋值给`b`。

```cmd
PS> (Get-Item .\secret.docx).creationtime

2023年2月22日 10:17:14

PS> .\timeStamp.exe "C:/users/admin/desktop/test.exe" "C:/users/admin/desktop/secret.docx"
[+] Success

PS> (Get-Item .\secret.docx).creationtime

2019年2月19日 12:45:32
```

