import java.sql.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

/**
 * Example 125 - Storing the Result of a Database Query
 * TODO: Senthil Kumaran - Write a database connection and list to print results
 */
class StoringResultsDatabase {

    static ArrayList<Map<String, Object>> getRows(Connection conn, String query)
        throws SQLException
    {
        Statement stmt = conn.createStatement();
        ResultSet rset = stmt.executeQuery(query);
        ResultSetMetaData rsmd = rset.getMetaData();
        int columncount = rsmd.getColumnCount();
        ArrayList<Map<String, Object>> queryResult = new ArrayList<Map<String, Object>>();
        while (rset.next()) {
            Map<String, Object> row = new HashMap<String, Object>();
            for (int i = 1; i <= columncount; i++) {
                row.put(rsmd.getColumnName(i), rset.getObject(i));
            }
            queryResult.add(row);
        }
        return queryResult;
    }

    static void printNameAndMsg(Collection<Map<String, Object>> coll) {
        for (Map<String, Object> row: coll)
            System.out.println(row.get("name") + ": " + row.get("msg"));

    }

    public static void main(String[] args) {

    }
}
