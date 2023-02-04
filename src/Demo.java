import net.sourceforge.tess4j.ITesseract;
import net.sourceforge.tess4j.Tesseract;
import net.sourceforge.tess4j.Tesseract1;
import net.sourceforge.tess4j.TesseractException;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Demo {
    public static void main(String[] args) {
//         ImageIO.scanForPlugins(); // 用于服务器环境
        File imageFile = new File("Tess4J/test/resources/test-data/eurotext.png");
        try {
            BufferedImage image =ImageIO.read(imageFile);
            //        ITesseract instance = new Tesseract(); // JNA Interface Mapping
            long starttime = System.currentTimeMillis();
            System.err.println("开始"+starttime);
            ITesseract instance = new Tesseract1(); // JNA Direct Mapping
            instance.setDatapath("Tess4J//tessdata"); // 将 <parentPath> 替换为 tessdata 父目录的路径
            instance.setLanguage("chi_sim");

            try {
//            String result = instance.doOCR(imageFile);
                String result = instance.doOCR(image);
                System.out.println(result);
                long endtime=System.currentTimeMillis();
                System.err.println("总用时"+(endtime-starttime)/1000+"秒");
            } catch (TesseractException e) {
                System.err.println(e.getMessage());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
