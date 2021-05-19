
#include "checker.h"

int get_next_line(char **line)
{
    int i = 0;
    int ret = 0;
    if(!line)
        return -1;
    if (!(*line = malloc(1024*1024)))
        return -1;
    while ((ret = read(0, &(*line)[i], 1)) == 1)
    {
        if ((*line)[i] == '\n')
        {
            (*line)[i] = 0;
            return 1;
        }
        i++;
    }
    (*line)[i] = 0;
    return (ret);
}


void	ft_cmdlist(char *line, t_stack *stacks)
{
	t_cmd *newcmd;

		if(!(stacks->head))
		{
			stacks->cmds = ft_newcmd(line);
			stacks->head = 1;
		}
		else
		{
			newcmd = ft_newcmd(line);
			ft_lstadd_backcmd(&stacks->cmds, newcmd);
		}
}

void	ft_readcmd(t_stack *stacks)
{
	int		r;
	char	*line;
	stacks->head = 0;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		ft_checkline(line, stacks);
		ft_cmdlist(line, stacks);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}

