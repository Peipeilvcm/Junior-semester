
import java.util.ArrayList;
import javax.swing.*;
import java.awt.*;

public class GuiTest extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private ArrayList<Employee> employees;
	
	//异常输出窗口信息
	private class ErrorDialog extends JDialog{
		private static final long serialVersionUID = 1L;
		
		public ErrorDialog(Dialog parent){
			super(parent);
			initialize();
		}
		
		private void initialize(){
			
			this.add(new JLabel("Error Input! Please Try Again!",JLabel.CENTER));
			this.pack();//适配窗口大小
			
			setTitle ("ERROR");
			setDefaultCloseOperation(DISPOSE_ON_CLOSE);
			setLocationRelativeTo(getParent());
			this.setModal(true);//有模式，其它窗口被屏蔽
		}
	}
	
	//add CommsionEmployee Dialog
	private class CommisionEmpDialog extends JDialog{
		private static final long serialVersionUID = 1L;

		public CommisionEmpDialog(Frame parent){
			super(parent);
			initialize();
		}
		
		private void initialize(){
			JPanel panel = new JPanel ();
			panel.setLayout (new GridLayout(6, 2));

			// First Name
			panel.add (new JLabel("First Name:",JLabel.CENTER));
			JTextField fN = new JTextField (10);
			panel.add (fN);

			// Last Name
			panel.add (new JLabel("Last Name:",JLabel.CENTER));
			JTextField lN = new JTextField (10);
			panel.add (lN);

			// Social Security Number
			panel.add (new JLabel("Social Security Number:",JLabel.CENTER));
			JTextField sSN = new JTextField (10);
			panel.add (sSN);

			// Gross Sales
			panel.add (new JLabel("Gross Sales:",JLabel.CENTER));
			JTextField grossSales = new JTextField (10);
			panel.add (grossSales);

			// Commission Rate
			panel.add (new JLabel("Commission Rate:",JLabel.CENTER));
			JTextField commissionRate = new JTextField (10);
			panel.add (commissionRate);

			// Buttons
			JButton buttonAdd = new JButton("Create");
			buttonAdd.addActionListener ((e) -> {
				try{
					//社会保险号不能为空
					if(sSN.getText().equals("")){
						throw new Exception();
					}
					
					employees.add (new CommisionEmployee (
						fN.getText(),
						lN.getText(),
						sSN.getText(),
						Integer.parseInt(grossSales.getText()),
						Double.parseDouble(commissionRate.getText())
					));
					JOptionPane.showMessageDialog(this,"create successfully");
					this.dispose();
				}
				catch (Exception ex){
					ErrorDialog dialog = new ErrorDialog(this);
					dialog.setVisible(true);
				}
			});
			JButton buttonCancel = new JButton("Cancel");
			buttonCancel.addActionListener ((e) -> {
				this.dispose();
			});
			panel.add (buttonAdd);
			panel.add (buttonCancel);

			// Add Panel
			getContentPane().add (panel);
			this.pack ();

			setTitle ("Create Commision Employee");
			setDefaultCloseOperation(DISPOSE_ON_CLOSE);
			setLocationRelativeTo(getParent());
		}
		
	}
	
	//add BasePlusCommsionEmployee Dialog
	private class BPCEmpDialog extends JDialog{
		private static final long serialVersionUID = 1L;
		
		public BPCEmpDialog(Frame parent){
			super(parent);
			initialize();
		}
		
		private void initialize(){
			
			JPanel panel = new JPanel();
			panel.setLayout (new GridLayout(7, 2));

			// First Name
			panel.add (new JLabel ("First Name:",JLabel.CENTER));
			JTextField fN = new JTextField (10);
			panel.add (fN);

			// Last Name
			panel.add (new JLabel ("Last Name:",JLabel.CENTER));
			JTextField lN = new JTextField (10);
			panel.add (lN);

			// Social Security Number
			panel.add (new JLabel ("Social Security Number:",JLabel.CENTER));
			JTextField sSN = new JTextField (10);
			panel.add (sSN);

			// Gross Sales
			panel.add (new JLabel ("Gross Sales:",JLabel.CENTER));
			JTextField grossSales = new JTextField (10);
			panel.add (grossSales);

			// Commission Rate
			panel.add (new JLabel ("Commission Rate:",JLabel.CENTER));
			JTextField commissionRate = new JTextField (10);
			panel.add (commissionRate);

			//Base Sales
			panel.add (new JLabel ("Base Salary:",JLabel.CENTER));
			JTextField baseSalary = new JTextField (10);
			panel.add (baseSalary);

			// Buttons
			JButton buttonAdd = new JButton("Create");
			buttonAdd.addActionListener ((e) -> {
				try{
					//社会保险号不能为空
					if(sSN.getText().equals("")){
						throw new Exception();
					}
					
					employees.add (new BasePlusCommisionEmployee (
						fN.getText(),
						lN.getText(),
						sSN.getText(),
						Integer.parseInt(grossSales.getText()),
						Double.parseDouble(commissionRate.getText()),
						Integer.parseInt(baseSalary.getText())
					));
					JOptionPane.showMessageDialog(this,"create successfully");
					this.dispose();
				}
				catch (Exception ex){
					ErrorDialog dialog = new ErrorDialog(this);
					dialog.setVisible(true);
				}
			});
			JButton buttonCancel = new JButton("Cancel");
			buttonCancel.addActionListener ((e) -> {
				this.dispose();
			});
			panel.add (buttonAdd);
			panel.add (buttonCancel);

			// Add Panel
			getContentPane().add(panel);
			this.pack();

			setTitle ("Create Base Plus Commision Employee");
			setDefaultCloseOperation (DISPOSE_ON_CLOSE);
			setLocationRelativeTo (getParent());
		}
	}
	
	private class AveEarningSearchDialog extends JDialog{
		private static final long serialVersionUID = 1L;

		public AveEarningSearchDialog(Frame parent)
		{
			super(parent);
			initUI ();
		}

		private void initUI ()
		{
			double ave = 0.0;
			if (employees.size () > 0)
			{
				for (Employee employee : employees)
					ave += employee.earning();
				ave /= employees.size ();
			}

			JPanel panel = new JPanel();
			panel.setLayout (new BoxLayout (panel, BoxLayout.Y_AXIS));

			// Content
			panel.add(new JLabel("Average Earning",JLabel.CENTER));
			panel.add(new JLabel("" + ave,JLabel.CENTER));

			// Add Panel
			this.add (panel);
			this.pack ();
			
			setTitle ("Average Earning");
			setDefaultCloseOperation (DISPOSE_ON_CLOSE);
			setLocationRelativeTo (getParent());
		}	
	}

	public GuiTest() {
		initialize();
		employees = new ArrayList<Employee>();
	}

	//Initialize the contents of the frame.
	private void initialize() {
		
		JPanel panel = new JPanel ();
		panel.setBackground(Color.white);
		panel.setLayout (new GridLayout(2, 1));
		JLabel label1 = new JLabel("EmployeeGui---Show!",JLabel.CENTER);
		label1.setFont(new Font("微软雅黑",1,15));
		JLabel label2 = new JLabel("Please select the command in the menu!",JLabel.CENTER);
		label2.setFont(new Font("微软雅黑",1,15));
		panel.add (label1);
		panel.add(label2);
		getContentPane().add(panel);
		this.pack();
		
		this.setTitle("Create_Or_Search");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLocationRelativeTo(null);
		
		this.getContentPane().setFont(new Font("微软雅黑", Font.BOLD, 16));
		this.getContentPane().setForeground(Color.WHITE);
		this.getContentPane().setBackground(Color.WHITE);
		this.setBounds(100, 100, 350, 150);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JMenuBar menuBar = new JMenuBar();
		this.setJMenuBar(menuBar);
		
		//一级菜单1
		JMenu mnEmpInfoInput = new JMenu("EmployeeInfoInput");
		mnEmpInfoInput.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 12));
		menuBar.add(mnEmpInfoInput);
		
		//二级菜单1-1
		JMenuItem mntmCommEmp = new JMenuItem("CommisionEmployee");
		mntmCommEmp.addActionListener((e) -> {
			CommisionEmpDialog dialog = new CommisionEmpDialog(this);
			dialog.setVisible(true);
		});
		mnEmpInfoInput.add(mntmCommEmp);
		
		//二级菜单1-2
		JMenuItem mntmBPCEmp = new JMenuItem("BasePlusCommisionEmployee");
		mntmBPCEmp.addActionListener((e) -> {
			BPCEmpDialog dialog = new BPCEmpDialog(this);
			dialog.setVisible(true);
		});
		mnEmpInfoInput.add(mntmBPCEmp);
		
		//一级菜单2
		JMenu mnSearch = new JMenu("Search");
		mnSearch.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 12));
		menuBar.add(mnSearch);
		
		//二级菜单2-1
		JMenuItem mntmAveEaringSearch = new JMenuItem("AverageEarningSearch");
		mntmAveEaringSearch.addActionListener((e) -> {
			AveEarningSearchDialog dialog = new AveEarningSearchDialog(this);
			dialog.setVisible(true);
		});
		mnSearch.add(mntmAveEaringSearch);
	}
	
	//Launch the application.
	public static void main(String[] args) {
		EventQueue.invokeLater(() -> {
			GuiTest window = new GuiTest();
			window.setVisible(true);
		});
	}
}