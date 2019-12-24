The .mica files will contain a scene description. .mica extention isn't enforced

All the data will be stored in ascii for ease of modifications and reading. The
format is the following :


->Digital fields:
'mm'	> position, signed integer in milimeter
'or'	> signed coordonate on x, y and z, treated as a vector, software
normalized, used for orientations.
'col'	> 0<>255 value for RGB
'an'	> 0<>360 angle for the cone in degree
'in'	> light intensity, unsigned integer in lumens


->Camera line:
ca 'mm mm mm' o 'or or or' f 'an'
position, then o refers to camera orientation and f refers to the fov in degrees


->Object lines:

-Sphere lines:
sp 'mm mm mm' s 'mm' c 'col col col'
position, then s refers to the sphere radius and c is the sphere color

-Plane lines:
pl 'mm mm mm' o 'or or or' c 'col col col'
position, then o refers to the plane normal and c is the plane color

-Cylinder lines:
cy 'mm mm mm' o 'or or or' s 'mm' c 'col col col'
position, then o refers to the cylinder's axis, s is the cylinder diameter, and
c is the cylinder color

-Cone lines:
co 'mm mm mm' o 'or or or' a 'an' c 'col col col'
position, then o refers to the cone axis, a refers to the cone angle and c is
the cone color

-Light lines:
l 'mm mm mm' i 'in'
where the position come first, and i is the light source intensity, in lumen


Empty lines are skipped, and every line beginning by '#' will be ignored.

Any line starting with a valid item id
> ['ca','sp','pl','cy','co','l']
will add one of the concerned item. Any innapropriate character in the line
will stop the parsing and fill every field with 0s, except for the size and
angle fields witch will be respectively assigned 1 and 60. A message will be
printed in the terminal to notify a missing field.

There is no order to follow, however only one camera is allowed, so adding
multiple camera lines will overwrite previous ones so only the last one will
actually count.

If the file has no readeable content, the program will start anyway, displaying
nothing as it should.