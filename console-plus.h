// https://github.com/neverforward/console-plus

#pragma once

#include <stdio.h>

// 光标移到x行y列
void to(int x, int y) {
	printf("\033[%d;%dH", x, y);
}

// 将光标移回(0,0)
void toraw() {
	printf("\033[H");
}

// 光标上移n行
void up(int n) {
	printf("\033[%dA", n);
}

// 光标下移n行
void down(int n) {
	printf("\033[%dB", n);
}

// 光标右移n列
void right(int n) {
	printf("\033[%dC", n);
}

// 光标左移n列
void left(int n) {
	printf("\033[%dD", n);
}

// 光标下移n行，移到行首
void downbigin(int n) {
	printf("\033[%dE", n);
}

// 光标上移n行，移到行首
void upbigin(int n) {
	printf("\033[%dF", n);
}

// 移动光标至列n
void tocol(int n) {
	printf("\033[%dG", n);
}

// 光标上移一行，按需可滚动
void upline() {
	printf("\033[M");
}

// 保存光标位置
void savecur() {
	printf("\033[7");
}

// 将光标恢复到上次保存的位置
void restorecur() {
	printf("\033[8");
}

// 清屏
void cas() {
	printf("\033[2J");
}

// 从光标擦到屏尾
void ces() {
	printf("\033[0J");
}

// 从光标擦到屏首
void cbs() {
	printf("\033[1J");
}

// 擦除保存的行
void css() {
	printf("\033[3J");
}

// 整行擦除
void cal() {
	printf("\033[2K");
}

// 从光标擦到行尾
void cel() {
	printf("\033[0k");
}

// 从光标擦到行首
void cbl() {
	printf("\033[1K");
}

// 粗体
void bold() {
	printf("\033[1m");
}

// 虚化
void bokeh() {
	printf("\033[2m");
}

// 斜体
void italic() {
	printf("\033[3m");
}

// 下划线
void underline() {
	printf("\033[4m");
}

// 闪烁
void flashing() {
	printf("\033[5m");
}

// 反色
void inverted() {
	printf("\033[7m");
}

// 隐形
void invisible() {
	printf("\033[8m");
}

// 删除线
void strikethrough() {
	printf("\033[9m");
}

// 重置
void reset() {
	printf("\033[0m");
}

// 黑
void black() {
	printf("\033[1;30m");
}

// 黑背景
void blackbg() {
	printf("\033[1;40m");
}

// 红
void red() {
	printf("\033[1;31m");
}

// 红背景
void redbg() {
	printf("\033[1;41m");
}

// 绿
void green() {
	printf("\033[1;32m");
}

// 绿背景
void greenbg() {
	printf("\033[1;42m");
}

// 黄
void yellow() {
	printf("\033[1;33m");
}

// 黄背景
void yellowbg() {
	printf("\033[1;43m");
}

// 蓝
void blue() {
	printf("\033[1;34m");
}

// 蓝背景
void bluebg() {
	printf("\033[1;44m");
}

// 品红
void magenta() {
	printf("\033[1;35m");
}

// 品红背景
void magentabg() {
	printf("\033[1;45m");
}

// 青
void cyan() {
	printf("\033[1;36m");
}

// 青背景
void cyanbg() {
	printf("\033[1;46m");
}

// 白
void white() {
	printf("\033[1;39m");
}

// 白背景
void whitebg() {
	printf("\033[1;49m");
}

// 亮黑
void light_black() {
	printf("\033[1;90m");
}

// 亮黑背景
void light_blackbg() {
	printf("\033[1;100m");
}

// 亮红
void light_red() {
	printf("\033[1;91m");
}

// 亮红背景
void light_redbg() {
	printf("\033[1;101m");
}

// 亮绿
void light_green() {
	printf("\033[1;92m");
}

// 亮绿背景
void light_greenbg() {
	printf("\033[1;102m");
}

// 亮黄
void light_yellow() {
	printf("\033[1;93m");
}

// 亮黄背景
void light_yellowbg() {
	printf("\033[1;103m");
}

// 亮蓝
void light_blue() {
	printf("\033[1;94m");
}

// 亮蓝背景
void light_bluebg() {
	printf("\033[1;104m");
}

// 亮品红
void light_magenta() {
	printf("\033[1;95m");
}

// 亮品红背景
void light_magentabg() {
	printf("\033[1;105m");
}

// 亮青
void light_cyan() {
	printf("\033[1;96m");
}

// 亮青背景
void light_cyanbg() {
	printf("\033[1;106m");
}

// 亮白
void light_white() {
	printf("\033[1;97m");
}

// 亮白背景
void light_whitebg() {
	printf("\033[1;109m");
}

/*
256色(id >= 0 id <= 255)
该表从最初的16种颜色(0∼15)开始。接下来的
216 种颜色(16−231) 可能由偏移16 的 3bpc
RGB 值组成，打包成一个值。
*/
void color256(short id) {
	printf("\033[38;5;%dm", id);
}

/*
256色背景(id >= 0 id <= 255)
该表从最初的16种颜色(0∼15)开始。接下来的
216 种颜色(16−231) 可能由偏移16 的 3bpc
RGB 值组成，打包成一个值。
*/
void color256bg(short id) {
	printf("\033[48;5;%dm", id);
}

// rgb色
void rgb(int r, int g, int b) {
	printf("\033[38;2;%d;%d;%dm", r, g, b);
}

// rgb背景
void rgbbg(int r, int g, int b) {
	printf("\033[48;2;%d;%d;%dm", r, g, b);
}

// 隐藏光标
void hidecur() {
	printf("\033[?25l");
}

// 显示光标
void showcur() {
	printf("\033[?25h");
}