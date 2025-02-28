# S3LotLoDThing
STEAM VERSION ONLY

Sets a bool and JMP's a JZ

0x011ecbc0 = Throttle Lot LoD Transitions under the Streaming category in the debug variables

0x00c63015 =
```asm
                             LAB_00c63002                                    XREF[1]:     00c62ee9(j)  
        00c63002 f3 0f 10 00     MOVSS      XMM0,dword ptr [EAX]
        00c63006 8b ce           MOV        param_1_00,ESI
        00c63008 f3 0f 11        MOVSS      dword ptr [ESP + local_c8],XMM0
                 44 24 08
        00c6300e e8 4d e8        CALL       FUN_00ab1860                                     undefined FUN_00ab1860(int param
                 e4 ff
        00c63013 84 c0           TEST       AL,AL
        00c63015 74 14           JZ         LAB_00c6302b
        00c63017 f3 0f 10        MOVSS      XMM0,dword ptr [ESP + local_c8]
                 44 24 08
        00c6301d f3 0f 5c        SUBSS      XMM0,dword ptr [EDI + 0xe0]
                 87 e0 00 
                 00 00
        00c63025 f3 0f 11        MOVSS      dword ptr [ESP + local_c8],XMM0
                 44 24 08
```
Seems to be related to frustum culling but I could be wrong. Either way it reduces stutter dramatically. Full streaming category editable in [Sims3SettingsSetter](https://github.com/sims3fiend/Sims3SettingsSetter)
