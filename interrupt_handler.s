/*
 * the instruction handler works something like this;
 * * First, the instruction vector is pushed onto the stack 
 * * Then, the interrupt calls back to the generic interrupt wrapper.
 * * The generic interrupt handler pushes all the registers onto the stack, thus
 *     saving the cpu state 
 * * The generic handler then calls the interrupt handler in C,
*/

/* 
 * apperently gcc doesn't recognize pushad
 */

.globl isr_wrapper
.align 4

generic_interrupt_wrapper:
	/* aparently gcc doesn't recognize pushad...*/
	pushal
	call generic_interrupt_handler
	popal
	add $4,%esp/* to get rid of the int vector */
	iret

.globl interrupt_wrapper_0
interrupt_wrapper_0:
	push $0
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_1
interrupt_wrapper_1:
	push $1
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_2
interrupt_wrapper_2:
	push $2
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_3
interrupt_wrapper_3:
	push $3
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_4
interrupt_wrapper_4:
	push $4
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_5
interrupt_wrapper_5:
	push $5
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_6
interrupt_wrapper_6:
	push $6
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_7
interrupt_wrapper_7:
	push $7
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_8
interrupt_wrapper_8:
	push $8
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_9
interrupt_wrapper_9:
	push $9
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_10
interrupt_wrapper_10:
	push $10
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_11
interrupt_wrapper_11:
	push $11
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_12
interrupt_wrapper_12:
	push $12
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_13
interrupt_wrapper_13:
	push $13
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_14
interrupt_wrapper_14:
	push $14
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_15
interrupt_wrapper_15:
	push $15
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_16
interrupt_wrapper_16:
	push $16
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_17
interrupt_wrapper_17:
	push $17
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_18
interrupt_wrapper_18:
	push $18
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_19
interrupt_wrapper_19:
	push $19
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_20
interrupt_wrapper_20:
	push $20
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_21
interrupt_wrapper_21:
	push $21
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_22
interrupt_wrapper_22:
	push $22
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_23
interrupt_wrapper_23:
	push $23
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_24
interrupt_wrapper_24:
	push $24
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_25
interrupt_wrapper_25:
	push $25
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_26
interrupt_wrapper_26:
	push $26
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_27
interrupt_wrapper_27:
	push $27
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_28
interrupt_wrapper_28:
	push $28
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_29
interrupt_wrapper_29:
	push $29
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_30
interrupt_wrapper_30:
	push $30
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_31
interrupt_wrapper_31:
	push $31
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_32
interrupt_wrapper_32:
	push $32
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_33
interrupt_wrapper_33:
	push $33
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_34
interrupt_wrapper_34:
	push $34
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_35
interrupt_wrapper_35:
	push $35
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_36
interrupt_wrapper_36:
	push $36
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_37
interrupt_wrapper_37:
	push $37
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_38
interrupt_wrapper_38:
	push $38
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_39
interrupt_wrapper_39:
	push $39
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_40
interrupt_wrapper_40:
	push $40
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_41
interrupt_wrapper_41:
	push $41
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_42
interrupt_wrapper_42:
	push $42
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_43
interrupt_wrapper_43:
	push $43
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_44
interrupt_wrapper_44:
	push $44
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_45
interrupt_wrapper_45:
	push $45
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_46
interrupt_wrapper_46:
	push $46
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_47
interrupt_wrapper_47:
	push $47
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_48
interrupt_wrapper_48:
	push $48
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_49
interrupt_wrapper_49:
	push $49
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_50
interrupt_wrapper_50:
	push $50
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_51
interrupt_wrapper_51:
	push $51
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_52
interrupt_wrapper_52:
	push $52
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_53
interrupt_wrapper_53:
	push $53
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_54
interrupt_wrapper_54:
	push $54
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_55
interrupt_wrapper_55:
	push $55
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_56
interrupt_wrapper_56:
	push $56
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_57
interrupt_wrapper_57:
	push $57
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_58
interrupt_wrapper_58:
	push $58
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_59
interrupt_wrapper_59:
	push $59
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_60
interrupt_wrapper_60:
	push $60
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_61
interrupt_wrapper_61:
	push $61
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_62
interrupt_wrapper_62:
	push $62
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_63
interrupt_wrapper_63:
	push $63
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_64
interrupt_wrapper_64:
	push $64
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_65
interrupt_wrapper_65:
	push $65
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_66
interrupt_wrapper_66:
	push $66
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_67
interrupt_wrapper_67:
	push $67
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_68
interrupt_wrapper_68:
	push $68
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_69
interrupt_wrapper_69:
	push $69
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_70
interrupt_wrapper_70:
	push $70
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_71
interrupt_wrapper_71:
	push $71
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_72
interrupt_wrapper_72:
	push $72
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_73
interrupt_wrapper_73:
	push $73
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_74
interrupt_wrapper_74:
	push $74
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_75
interrupt_wrapper_75:
	push $75
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_76
interrupt_wrapper_76:
	push $76
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_77
interrupt_wrapper_77:
	push $77
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_78
interrupt_wrapper_78:
	push $78
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_79
interrupt_wrapper_79:
	push $79
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_80
interrupt_wrapper_80:
	push $80
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_81
interrupt_wrapper_81:
	push $81
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_82
interrupt_wrapper_82:
	push $82
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_83
interrupt_wrapper_83:
	push $83
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_84
interrupt_wrapper_84:
	push $84
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_85
interrupt_wrapper_85:
	push $85
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_86
interrupt_wrapper_86:
	push $86
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_87
interrupt_wrapper_87:
	push $87
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_88
interrupt_wrapper_88:
	push $88
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_89
interrupt_wrapper_89:
	push $89
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_90
interrupt_wrapper_90:
	push $90
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_91
interrupt_wrapper_91:
	push $91
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_92
interrupt_wrapper_92:
	push $92
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_93
interrupt_wrapper_93:
	push $93
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_94
interrupt_wrapper_94:
	push $94
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_95
interrupt_wrapper_95:
	push $95
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_96
interrupt_wrapper_96:
	push $96
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_97
interrupt_wrapper_97:
	push $97
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_98
interrupt_wrapper_98:
	push $98
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_99
interrupt_wrapper_99:
	push $99
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_100
interrupt_wrapper_100:
	push $100
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_101
interrupt_wrapper_101:
	push $101
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_102
interrupt_wrapper_102:
	push $102
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_103
interrupt_wrapper_103:
	push $103
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_104
interrupt_wrapper_104:
	push $104
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_105
interrupt_wrapper_105:
	push $105
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_106
interrupt_wrapper_106:
	push $106
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_107
interrupt_wrapper_107:
	push $107
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_108
interrupt_wrapper_108:
	push $108
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_109
interrupt_wrapper_109:
	push $109
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_110
interrupt_wrapper_110:
	push $110
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_111
interrupt_wrapper_111:
	push $111
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_112
interrupt_wrapper_112:
	push $112
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_113
interrupt_wrapper_113:
	push $113
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_114
interrupt_wrapper_114:
	push $114
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_115
interrupt_wrapper_115:
	push $115
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_116
interrupt_wrapper_116:
	push $116
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_117
interrupt_wrapper_117:
	push $117
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_118
interrupt_wrapper_118:
	push $118
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_119
interrupt_wrapper_119:
	push $119
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_120
interrupt_wrapper_120:
	push $120
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_121
interrupt_wrapper_121:
	push $121
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_122
interrupt_wrapper_122:
	push $122
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_123
interrupt_wrapper_123:
	push $123
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_124
interrupt_wrapper_124:
	push $124
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_125
interrupt_wrapper_125:
	push $125
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_126
interrupt_wrapper_126:
	push $126
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_127
interrupt_wrapper_127:
	push $127
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_128
interrupt_wrapper_128:
	push $128
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_129
interrupt_wrapper_129:
	push $129
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_130
interrupt_wrapper_130:
	push $130
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_131
interrupt_wrapper_131:
	push $131
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_132
interrupt_wrapper_132:
	push $132
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_133
interrupt_wrapper_133:
	push $133
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_134
interrupt_wrapper_134:
	push $134
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_135
interrupt_wrapper_135:
	push $135
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_136
interrupt_wrapper_136:
	push $136
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_137
interrupt_wrapper_137:
	push $137
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_138
interrupt_wrapper_138:
	push $138
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_139
interrupt_wrapper_139:
	push $139
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_140
interrupt_wrapper_140:
	push $140
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_141
interrupt_wrapper_141:
	push $141
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_142
interrupt_wrapper_142:
	push $142
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_143
interrupt_wrapper_143:
	push $143
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_144
interrupt_wrapper_144:
	push $144
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_145
interrupt_wrapper_145:
	push $145
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_146
interrupt_wrapper_146:
	push $146
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_147
interrupt_wrapper_147:
	push $147
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_148
interrupt_wrapper_148:
	push $148
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_149
interrupt_wrapper_149:
	push $149
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_150
interrupt_wrapper_150:
	push $150
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_151
interrupt_wrapper_151:
	push $151
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_152
interrupt_wrapper_152:
	push $152
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_153
interrupt_wrapper_153:
	push $153
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_154
interrupt_wrapper_154:
	push $154
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_155
interrupt_wrapper_155:
	push $155
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_156
interrupt_wrapper_156:
	push $156
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_157
interrupt_wrapper_157:
	push $157
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_158
interrupt_wrapper_158:
	push $158
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_159
interrupt_wrapper_159:
	push $159
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_160
interrupt_wrapper_160:
	push $160
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_161
interrupt_wrapper_161:
	push $161
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_162
interrupt_wrapper_162:
	push $162
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_163
interrupt_wrapper_163:
	push $163
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_164
interrupt_wrapper_164:
	push $164
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_165
interrupt_wrapper_165:
	push $165
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_166
interrupt_wrapper_166:
	push $166
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_167
interrupt_wrapper_167:
	push $167
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_168
interrupt_wrapper_168:
	push $168
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_169
interrupt_wrapper_169:
	push $169
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_170
interrupt_wrapper_170:
	push $170
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_171
interrupt_wrapper_171:
	push $171
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_172
interrupt_wrapper_172:
	push $172
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_173
interrupt_wrapper_173:
	push $173
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_174
interrupt_wrapper_174:
	push $174
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_175
interrupt_wrapper_175:
	push $175
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_176
interrupt_wrapper_176:
	push $176
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_177
interrupt_wrapper_177:
	push $177
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_178
interrupt_wrapper_178:
	push $178
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_179
interrupt_wrapper_179:
	push $179
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_180
interrupt_wrapper_180:
	push $180
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_181
interrupt_wrapper_181:
	push $181
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_182
interrupt_wrapper_182:
	push $182
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_183
interrupt_wrapper_183:
	push $183
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_184
interrupt_wrapper_184:
	push $184
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_185
interrupt_wrapper_185:
	push $185
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_186
interrupt_wrapper_186:
	push $186
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_187
interrupt_wrapper_187:
	push $187
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_188
interrupt_wrapper_188:
	push $188
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_189
interrupt_wrapper_189:
	push $189
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_190
interrupt_wrapper_190:
	push $190
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_191
interrupt_wrapper_191:
	push $191
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_192
interrupt_wrapper_192:
	push $192
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_193
interrupt_wrapper_193:
	push $193
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_194
interrupt_wrapper_194:
	push $194
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_195
interrupt_wrapper_195:
	push $195
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_196
interrupt_wrapper_196:
	push $196
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_197
interrupt_wrapper_197:
	push $197
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_198
interrupt_wrapper_198:
	push $198
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_199
interrupt_wrapper_199:
	push $199
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_200
interrupt_wrapper_200:
	push $200
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_201
interrupt_wrapper_201:
	push $201
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_202
interrupt_wrapper_202:
	push $202
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_203
interrupt_wrapper_203:
	push $203
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_204
interrupt_wrapper_204:
	push $204
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_205
interrupt_wrapper_205:
	push $205
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_206
interrupt_wrapper_206:
	push $206
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_207
interrupt_wrapper_207:
	push $207
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_208
interrupt_wrapper_208:
	push $208
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_209
interrupt_wrapper_209:
	push $209
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_210
interrupt_wrapper_210:
	push $210
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_211
interrupt_wrapper_211:
	push $211
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_212
interrupt_wrapper_212:
	push $212
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_213
interrupt_wrapper_213:
	push $213
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_214
interrupt_wrapper_214:
	push $214
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_215
interrupt_wrapper_215:
	push $215
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_216
interrupt_wrapper_216:
	push $216
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_217
interrupt_wrapper_217:
	push $217
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_218
interrupt_wrapper_218:
	push $218
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_219
interrupt_wrapper_219:
	push $219
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_220
interrupt_wrapper_220:
	push $220
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_221
interrupt_wrapper_221:
	push $221
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_222
interrupt_wrapper_222:
	push $222
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_223
interrupt_wrapper_223:
	push $223
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_224
interrupt_wrapper_224:
	push $224
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_225
interrupt_wrapper_225:
	push $225
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_226
interrupt_wrapper_226:
	push $226
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_227
interrupt_wrapper_227:
	push $227
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_228
interrupt_wrapper_228:
	push $228
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_229
interrupt_wrapper_229:
	push $229
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_230
interrupt_wrapper_230:
	push $230
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_231
interrupt_wrapper_231:
	push $231
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_232
interrupt_wrapper_232:
	push $232
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_233
interrupt_wrapper_233:
	push $233
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_234
interrupt_wrapper_234:
	push $234
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_235
interrupt_wrapper_235:
	push $235
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_236
interrupt_wrapper_236:
	push $236
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_237
interrupt_wrapper_237:
	push $237
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_238
interrupt_wrapper_238:
	push $238
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_239
interrupt_wrapper_239:
	push $239
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_240
interrupt_wrapper_240:
	push $240
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_241
interrupt_wrapper_241:
	push $241
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_242
interrupt_wrapper_242:
	push $242
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_243
interrupt_wrapper_243:
	push $243
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_244
interrupt_wrapper_244:
	push $244
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_245
interrupt_wrapper_245:
	push $245
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_246
interrupt_wrapper_246:
	push $246
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_247
interrupt_wrapper_247:
	push $247
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_248
interrupt_wrapper_248:
	push $248
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_249
interrupt_wrapper_249:
	push $249
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_250
interrupt_wrapper_250:
	push $250
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_251
interrupt_wrapper_251:
	push $251
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_252
interrupt_wrapper_252:
	push $252
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_253
interrupt_wrapper_253:
	push $253
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_254
interrupt_wrapper_254:
	push $254
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_255
interrupt_wrapper_255:
	push $255
	jmp generic_interrupt_wrapper
.globl interrupt_wrapper_256
interrupt_wrapper_256:
	push $256
	jmp generic_interrupt_wrapper
