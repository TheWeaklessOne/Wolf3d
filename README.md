# Wolf3d

Multithread raycasting engine builded on SDL2

![](promo.gif)

Several options are available (see [Keyboard shortcuts](https://github.com/TheWeaklessOne/Wolf3d#keyboard-shortcuts) or/and [Mouse controls](https://github.com/TheWeaklessOne/Wolf3d#mouse-controls) sections for more infos) :
* Walk forward/backward along the direction of view
* Change the ray accuracy
* Change the maximum ray range
* Speed up

## Install & launch
```bash
git clone https://github.com/TheWeaklessOne/Wolf3d ~/Wolf3d
cd ~/Wolf3d && ./install_frameworks.sh && make && ./Wolf3d map
```
You have to launch the program with a parameter. This is the path to map source.<br />

Example :

Open standart map ⇣
```bash
./Wolf3d map
```
![standart map](https://i.imgur.com/DX5ih2h.png)
## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;ESC&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move forward (faster with <kbd>&nbsp;shift&nbsp;</kbd></td>)
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move backwards (faster with <kbd>&nbsp;shift&nbsp;</kbd></td>)</td>
<td valign="top" align="center"><kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change view angle to the left (faster with <kbd>&nbsp;shift&nbsp;</kbd></td>)</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change view angle to the right (faster with <kbd>&nbsp;shift&nbsp;</kbd></td>)</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase maximum ray range</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease maximum ray range</td>
<td valign="top" align="center"><kbd>&nbsp;-&nbsp;</kdb></td>
</tr>
<tr>
<td valign="top" height="30px">Increase ray accuracy</td>
<td valign="top" align="center"><kbd>&nbsp;Shift&nbsp;</kdb> and <kbd>&nbsp;+&nbsp;</kdb></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease Increase ray accuracy</td>
<td valign="top" align="center"><kbd>&nbsp;Shift&nbsp;</kdb> and <kbd>&nbsp;-&nbsp;</kdb></td>
</tr>
</tbody>
</table>

## Screenshots
![another_angle](https://i.imgur.com/YUtLEm3.png)
![4k_textures](https://i.imgur.com/NbnOwRU.png)
