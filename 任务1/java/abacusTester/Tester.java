package abacusTester;

//import java.awt.Color;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Tester
{
	private JFrame frame;
	private Abacus abacus;
	private Clock clock;
	private Exercise exercise;
	private JPanel usrinfo;
	private JPanel nowanswerinfo;
	private boolean nowanswerinfoVisible = false;
	private JFrame endusrinfo;
	private final int srceenWidth = (int) Toolkit.getDefaultToolkit().getScreenSize().getWidth();
	private final int srceenHeight = (int) Toolkit.getDefaultToolkit().getScreenSize().getHeight();
	private final int width = 710;
	private final int height = 400;
	private final int frameX = (srceenWidth - width) / 2;
	private final int frameY = (srceenHeight - height) / 2;
	private final int width2 = 300;
	private final int height2 = 300;
	private final int frame2X = (srceenWidth - width2) / 2;
	private final int frame2Y = (srceenHeight - height2) / 2;

	private final int textlength = 16;
	private final int testnum = 10;

	private JLabel thename;
	private JTextField name;
//	private JTextField nowexercise;
	private JTextArea textCalculateResult;
	private JTextArea endinfo;
	private int[] calculateResult = new int[testnum];
	private int totalRightNumber = 0;
	private int grade = 0;
	private JButton start;
	private JButton ensure;
	private JButton end;

	private boolean[] testresult = new boolean[testnum];

	public Tester()
	{
		frame = new JFrame("电子算盘");
		abacus = new Abacus();
		clock = new Clock();
		usrinfo = new JPanel();

		setframe();
		setabacus();
		setclock();
		setExercise();
		setUsrinfo();
		setNowanserinfo(0);
		nowanswerinfo.setVisible(nowanswerinfoVisible);
	}

	private void setframe()
	{
		frame.setLayout(null);
		frame.setBounds(frameX, frameY, width, height);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

	private void setabacus()
	{
		abacus.setBounds(10, 10, Abacus.getAbacuspanelWidth(), Abacus.getAbacuspanelHeight());
		frame.add(abacus);
	}

	private void reabacus()
	{
		frame.remove(abacus);
		abacus = new Abacus();
		abacus.setBounds(10, 10, Abacus.getAbacuspanelWidth(), Abacus.getAbacuspanelHeight());
		frame.add(abacus);
		abacus.repaint();
		frame.validate();
	}

	private void setclock()
	{
		clock.setBounds(430, 170, Clock.getClockpanelWidth(), Clock.getClockpanelHeight());
		frame.add(clock);
	}

	private void setExercise()
	{
		exercise = new Exercise();
//		exercise.setBackground(Color.BLUE);
		exercise.setBounds(585, 10, Exercise.getExercisepanelWidth(), Exercise.getExercisepanelHeight());
		exercise.setVisible(false);
		frame.add(exercise);
	}

	private void setUsrinfo()
	{
		usrinfo.setBounds(410, 10, 170, 120);
//		usrinfo.setBackground(Color.RED);

		thename = new JLabel("用户名: ");
		usrinfo.add(thename);

//		name = new JTextField("name:");
		name = new JTextField(textlength);
		name.setBounds(430, 10, 200, 150);
//		name.setBackground(Color.GREEN);
		name.addKeyListener(new Text());
		usrinfo.add(name);

		setStart();
		setEnsure();
		setEnd();

//		System.out.println("setusrinfo");
//		frame.add(name);
		frame.add(usrinfo);
		frame.validate();
	}

	private void setStart()
	{
		start = new JButton("开始");
		start.addActionListener(new Click());
		usrinfo.add(start);
	}

	private void setEnsure()
	{
		ensure = new JButton("确认");
		ensure.addActionListener(new Click());
		ensure.setVisible(false);
		usrinfo.add(ensure);
	}

	private void setEnd()
	{
		end = new JButton("结束");
		end.addActionListener(new Click());
		end.setVisible(false);
		usrinfo.add(end);
	}

	private void setNowanserinfo(int counter)
	{
//		System.out.println(counter);

		nowanswerinfo = new JPanel();
		nowanswerinfo.setBounds(585, 250, 100, 70);
//		nowanswerinfo.setBackground(Color.RED);

//		nowexercise = new JTextField();
//		nowexercise.setEditable(false);
//		nowexercise.setText("现在是第" + counter+1 + "题");
//		nowanswerinfo.add(nowexercise);

		if (counter > 0)
		{
			calculateResult[counter - 1] = exercise.getResult(counter - 1);
			testresult[counter - 1] = false;
			if (calculateResult[counter - 1] == abacus.getTotalNumber())
			{
				totalRightNumber++;
				testresult[counter - 1] = true;
				grade += 10;
//				System.out.println("trn++");
			}
		}
//		System.out.println(abacus.getTotalNumber() + " " + calculateResult);

		textCalculateResult = new JTextArea();
		textCalculateResult.setEditable(false);
		textCalculateResult.setText("总题数:" + testnum + "\n已答题数:" + counter + "\n已做对题数:" + totalRightNumber);
		nowanswerinfo.add(textCalculateResult);

//		System.out.println("setnowanserinfo");
//		nowanswerinfo.setVisible(nowanswerinfoVisible);
		frame.add(nowanswerinfo);
		frame.validate();
	}

	private String getTestresult(int i)
	{
		return testresult[i] ? "right" : "wrong";
	}

	private void setEndusrinfo()
	{
		endusrinfo = new JFrame();
		endusrinfo.setBounds(frame2X, frame2Y, width2, height2);
		endinfo = new JTextArea();
		endinfo.setEditable(false);
		String username = "username:" + name.getText();
		String test[] = new String[testnum];
		String testes = "";
		for (int i = 0; i < testnum; ++i)
		{
			test[i] = exercise.getText(i) + calculateResult[i] + getTestresult(i);
			testes = testes + test[i] + "\n";
		}
		int time = clock.getTime();
		endinfo.setText(username + "\ntestes:\n" + testes + "time:" + time + "s\ngrade:" + grade);
		endusrinfo.add(endinfo);
		endusrinfo.setVisible(true);
	}

	private class Text implements KeyListener
	{

		@Override
		public void keyPressed(KeyEvent arg0)
		{
			// TODO 自动生成的方法存根

		}

		@Override
		public void keyReleased(KeyEvent arg0)
		{
			// TODO 自动生成的方法存根

		}

		@Override
		public void keyTyped(KeyEvent e)
		{
			String s = name.getText();
			if (s.length() >= textlength)
			{
				e.consume();
			}
		}

	}

	private class Click implements ActionListener
	{
		private int counter = 1;

		public void actionPerformed(ActionEvent e)
		{
			if (e.getSource() == start)
			{
				name.setEditable(false);
//				exercise.exerciseStart();
				exercise.setVisible(true);
				setNowanserinfo(0);
				nowanswerinfo.setVisible(true);
				clock.clockStart();
				start.setVisible(false);
				ensure.setVisible(true);
				end.setVisible(true);
			}
			if (e.getSource() == ensure)
			{
				if (counter <= 10)
				{
					setNowanserinfo(counter);
					++counter;
					reabacus();
				}
			}
			if (e.getSource() == end)
			{
				clock.clockEnd();
				setEndusrinfo();
			}
		}
	}

	public static void main(String[] args)
	{
		@SuppressWarnings("unused")
		Tester t = new Tester();
	}

}
