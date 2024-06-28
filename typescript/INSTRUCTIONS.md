To run we will need nodejs, npm and tsx

>sudo apt install nodejs
>sudo apt install npm

tsx requires newer node than comes by default so I recommend installing n and using it to get newer version of node
> sudo npm i n -g
> sudo n 20

finally we can install tsx
> sudo npm i tsx -g

Do note the global installations. (-g). 

and to run then:

> sudo npx tsx bogosort.ts