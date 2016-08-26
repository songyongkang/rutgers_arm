import sys,os
import fnmatch

path =  os.getcwd()
dirs = os.listdir(path)

for filename in dirs:
    # print filename
    if fnmatch.fnmatch(filename,"*.yaml"):
        g = open(filename,'r')
        data = g.readlines()
        g.close()
        g = open(filename,'w')
        for line in data:
            if line[0]!="-":
                print "help "+filename
                line = '- '+line
            new_data = line.replace("- [","-\n  relative_config: [")
            new_data = new_data.replace("]","]\n  release_mode: 1\n  grasp_mode: 2")
            g.write(new_data)
        g.close()




# with open("vis_launch_params.launch",'r') as g:
#     data = g.readlines();