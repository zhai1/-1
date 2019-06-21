package abacusTester;

import java.awt.Color;
import java.util.Random;

import javax.swing.JPanel;
import javax.swing.JTextField;

public class Exercise extends JPanel
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 7083304702770157328L;

	private static final int exercisePanel_Width = 110;
	private static final int exercisePanel_Height = 235;

	private int testnum = 10;
	private final int textlength = 10;

	private JTextField[] text = new JTextField[testnum];
	private int[] testa = new int[testnum];
	private int[] testb = new int[testnum];
	private int[] testc = new int[testnum];
	private char[] testo = new char[testnum];
	private Random random;

	public Exercise()
	{
		setExercise();
	}

	private void setExercise()
	{
		for (int i = 0; i < testnum; ++i)
		{
			text[i] = new JTextField(textlength);
			text[i].setEditable(false);
//			text[i].setEnabled(false);
			text[i].setBorder(null);
//			text[i].setBackground(null);

			random = new Random();
			int j = random.nextInt(4);
			char[] c = new char[] { '+', '-', '*', '/' };
			testo[i] = c[j];
			switch (testo[i])
			{
			case '+':
				testa[i] = random.nextInt(25);
				testb[i] = random.nextInt(25);
				testc[i] = testa[i] + testb[i];
				break;
			case '-':
				testa[i] = random.nextInt(50);
				testb[i] = random.nextInt(testa[i] + 1);
				testc[i] = testa[i] - testb[i];
				break;
			case '*':
				do
				{
					testa[i] = random.nextInt(10) + 1;
					testb[i] = random.nextInt((int) (50 / testa[i])) + 1;
					testc[i] = testa[i] * testb[i];
				} while (testc[i] >= 50);
				break;
			case '/':
				do
				{
					testc[i] = random.nextInt(10) + 1;
					testb[i] = random.nextInt((int) (50 / testc[i])) + 1;
					testa[i] = testc[i] * testb[i];
				} while (testa[i] >= 50);
				break;
			}
//			System.out.println(i +" a:" + testa[i] + " o:" + testo[i] + " b:" + testb[i] + " c:" + testc[i]);
			text[i].setForeground(Color.BLACK);
			text[i].setBackground(Color.WHITE);
			text[i].setText(i + 1 + ": " + testa[i] + testo[i] + testb[i] + "= ?");
			this.add(text[i]);
		}
	}

	public String getText(int i)
	{
		return text[i].getText();
	}

	public int getResult(int i)
	{
		return testc[i];
	}

	public static int getExercisepanelWidth()
	{
		return exercisePanel_Width;
	}

	public static int getExercisepanelHeight()
	{
		return exercisePanel_Height;
	}

	public void setTestnum(int testnum)
	{
		this.testnum = testnum;
	}

}
