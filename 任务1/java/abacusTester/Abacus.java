package abacusTester;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JPanel;

public class Abacus extends JPanel
{

	/**
	 * 
	 */
	private static final long serialVersionUID = 2477889490360026349L;

	private static final int abacusPanel_Width = 400;
	private static final int abacusPanel_Height = 300;

	private int totalNumber;
	private boolean[] isAddFive = new boolean[5];
	private int[] number = new int[5];
	private ImageIcon bead1 = new ImageIcon("src/images/bead1.png");
	private ImageIcon bead2 = new ImageIcon("src/images/bead2.png");
	private JButton[][] button1 = new JButton[2][5];
	private JButton[][] button2 = new JButton[5][5];
	private GridLayout gl1 = new GridLayout(2, 5);
	private GridLayout gl2 = new GridLayout(5, 5);

	private JPanel j1;
	private JPanel j2;

	public Abacus()
	{
		abacusPanel();
	}

	public void addTotalNumber()
	{
		for (int j = 0; j < 5; j++)
		{
			if (isAddFive[j] == true && number[j] < 5)
				number[j] = number[j] + 5;
			else if (isAddFive[j] == false && number[j] >= 5)
				number[j] = number[j] - 5;
		}
		totalNumber = 0;
		for (int j = 0; j < 5; j++)
		{
			totalNumber = totalNumber + number[j] * (int) Math.pow(10, (double) j);
		}
	}

	public int getTotalNumber()
	{
		return totalNumber;
	}

	private void abacusPanel()
	{
		this.setBackground(Color.BLUE);
		this.setLayout(null);

		j1 = new JPanel();
		j1.setLayout(gl1);
		j1.setBounds(this.getX() + 10, this.getY() + 10, 380, 80);
		j1.setBackground(Color.WHITE);
		this.add(j1);

		j2 = new JPanel();
		j2.setLayout(gl2);
		j2.setBounds(this.getX() + 10, this.getY() + 100, 380, 190);
		j2.setBackground(Color.WHITE);
		this.add(j2);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				button1[i][j] = new JButton("");
				button1[i][j].addActionListener(new ClickIt());
				button1[i][j].setBorderPainted(false);
				button1[i][j].setContentAreaFilled(false);
				if (i != 1)
				{
					button1[i][j].setIcon(bead1);
					button1[i][j].setBackground(Color.GRAY);
				}
				j1.add(button1[i][j]);
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				button2[i][j] = new JButton("");
				button2[i][j].addActionListener(new ClickIt());
				button2[i][j].setBorderPainted(false);
				button2[i][j].setContentAreaFilled(false);
				if (i != 0)
				{
					button2[i][j].setIcon(bead2);
					button2[i][j].setBackground(Color.GRAY);
				}
				j2.add(button2[i][j]);
			}
		}
	}

	class ClickIt implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 5; j++)
					if (e.getSource() == button1[i][j])
					{
						if (i == 1)
						{
							isAddFive[5 - j - 1] = false;
							button1[0][j].setIcon(bead1);
							button1[1][j].setIcon(null);
						} else if (i == 0)
						{
							isAddFive[5 - j - 1] = true;
							button1[1][j].setIcon(bead1);
							button1[0][j].setIcon(null);
						}
					}
			for (int i = 0; i <= 4; i++)
				for (int j = 0; j < 5; j++)
					if (e.getSource() == button2[i][j])
					{
						number[5 - j - 1] = i;
						for (int k = 1; k <= 4; k++)
						{
							button2[k][j].setIcon(bead2);
						}
						button2[0][j].setIcon(bead2);
						button2[i][j].setIcon(null);
					}
			addTotalNumber();
//			System.out.println(getTotalNumber());
		}
	}

	public static int getAbacuspanelWidth()
	{
		return abacusPanel_Width;
	}

	public static int getAbacuspanelHeight()
	{
		return abacusPanel_Height;
	}

}
